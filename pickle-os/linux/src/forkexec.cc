#include "forkexec.h"

#include <pickle/os/oserror.h>

#include <unistd.h>
#include <fcntl.h>

namespace pickle {

std::variant<OSError, std::shared_ptr<Subprocess>> create_subprocess(std::string const & path) {
  auto name = path;
  char * const args[]{name.data(), nullptr, nullptr};

  int to[2];
  int from[2];
  ::pipe(to);
  ::pipe(from);

  int error_chanel[2];
  ::pipe(error_chanel);
  ::fcntl(error_chanel[1], F_SETFD, fcntl(error_chanel[1], F_GETFD) | FD_CLOEXEC);

  auto const pid = ::fork();
  if(pid < 0) {
    return OSError{};
  }

  if(pid == 0) {
    ::dup2(to[0], STDIN_FILENO);
    ::dup2(from[1], STDOUT_FILENO);

    ::close(to[1]);
    ::close(from[0]);

    ::close(error_chanel[0]);
    ::execv(path.data(), args);
    ::write(error_chanel[1], &errno, sizeof(int));
    std::exit(1);
  }

  ::close(to[0]);
  ::close(from[1]);

  ::close(error_chanel[1]);
  do {
    int error = 0;
    auto count = ::read(error_chanel[0], &error, sizeof(int));
    if(count > 0) {
      return OSError{};
    }
  } while(errno == EAGAIN || errno == EINTR);
  ::close(error_chanel[0]);

  return std::shared_ptr<Subprocess>{ std::make_shared<ForkExec>(pid, to[1], from[0]) };
};

ForkExec::ForkExec(pid_t child, int to, int from)
  : _io(std::make_unique<PipeStream>(to, from))
{
}

std::iostream & ForkExec::io() const {
  return *_io;
}

} // namespace pickle
