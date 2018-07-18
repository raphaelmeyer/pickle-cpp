#include "engine.h"

#include "error.h"

#include <unistd.h>

#include <cstring>

namespace pickle {

std::variant<std::iostream, Error> start_engine()
{
  char const * path{"../cucumber-pickle-runner"};
  char name[]{"cucumber-pickle-runner"};
  char flag[]{"--debug"};

  char * const args[]{name, flag, nullptr};

  int to[2];
  int from[2];

  if(::pipe(to) < 0) {
    std::cerr << "error: " << strerror(errno) << "\n";
    std::exit(1);
  }

  if(::pipe(from) < 0) {
    std::cerr << "error: " << strerror(errno) << "\n";
    std::exit(1);
  }

  auto const pid = ::fork();
  if(pid == 0) {
    ::dup2(to[0], STDIN_FILENO);
    ::dup2(from[1], STDOUT_FILENO);

    ::close(to[1]);
    ::close(from[0]);

    if(::execv(path, args) < 0) {
      std::cerr << "error: " << strerror(errno) << "\n";
      std::exit(1);
    }
  } else {
    ::close(to[0]);
    ::close(from[1]);
  }

  return Error{"not yet implemented"};
}

} // namespace pickle
