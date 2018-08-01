#include "subprocess.h"

#include "error.h"

#include <unistd.h>
#include <fcntl.h>

#include <vector>

namespace pickle {

std::iostream & Subprocess::io() {
  return _io;
}

std::variant<Error, Subprocess> create_subprocess(std::string const & path) {
  auto name = path;
  char * const args[]{name.data(), nullptr, nullptr};

  int error_chanel[2];
  ::pipe(error_chanel);
  ::fcntl(error_chanel[1], F_SETFD, fcntl(error_chanel[1], F_GETFD) | FD_CLOEXEC);

  auto const pid = ::fork();
  if(pid < 0) {
    return Error{};
  }

  if(pid == 0) {
    ::close(error_chanel[0]);
    ::execv(path.data(), args);
    ::write(error_chanel[1], &errno, sizeof(int));
    std::exit(1);
  }

  ::close(error_chanel[1]);
  do {
    int error = 0;
    auto count = ::read(error_chanel[0], &error, sizeof(int));
    if(count > 0) {
      return Error{};
    }
  } while(errno == EAGAIN || errno == EINTR);
  ::close(error_chanel[0]);

  return Subprocess{};
};

} // namespace pickle
