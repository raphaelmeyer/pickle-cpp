#include "runner.h"

#include <pickle/os/oserror.h>
#include <pickle/os/subprocess.h>

int main() {
  pickle::Runner runner{{}};

  auto result = pickle::create_subprocess("../cucumber-pickle-runner");
  if(auto error = std::get_if<pickle::OSError>(&result); error) {
    std::cerr << error->what << "\n";
    return 1;
  }

  auto subprocess = std::get<std::shared_ptr<pickle::Subprocess>>(result);
  runner.run(subprocess->io());
  return 0;
}
