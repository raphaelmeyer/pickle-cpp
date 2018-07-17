#include <unistd.h>
#include <string.h>

#include <string>
#include <iostream>

int main() {

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

    std::string const start{R"json({ "type": "start", "featuresConfig": { "filters": { "tagExpression": "" }, "order": {} }, "runtimeConfig": { "maxParallel": 1 }, "supportCodeConfig": {}, "stepDefinitions": [] }
)json"};

    ::write(to[1], start.c_str(), start.size());

    char buf[1024];
    auto const size = ::read(from[0], buf, 1024);
    if(size < 0) {
      std::cerr << "error: " << strerror(errno) << "\n";
      std::exit(1);
    }

    std::string const response{buf, static_cast<std::size_t>(size)};

    std::cout << "response: " << response << "\n";
  }

}

