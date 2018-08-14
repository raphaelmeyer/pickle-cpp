#include "subprocess.h"

#include "error.h"
#include "pipestream.h"

#include <unistd.h>
#include <fcntl.h>

#include <vector>

namespace pickle {

Subprocess::Subprocess(pid_t child, int to, int from)
  : _io(std::make_unique<PipeStream>(to, from))
{

}

std::iostream & Subprocess::io() {
  return *_io;
}

std::variant<Error, Subprocess> create_subprocess(std::string const & path) {
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
    return Error{};
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
      return Error{};
    }
  } while(errno == EAGAIN || errno == EINTR);
  ::close(error_chanel[0]);

  return Subprocess{pid, to[1], from[0]};
};

} // namespace pickle
