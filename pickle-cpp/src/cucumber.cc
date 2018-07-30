#include <pickle-cpp/cucumber.h>

namespace cucumber {

void Given(std::string name, std::function<void(Pickle const &)> definition) {
}

void When(std::string name, std::function<void(Pickle const &)> definition) {
}

void Then(std::string name, std::function<void(Pickle const &)> definition) {
}

void run() {
  /*
  auto result = pickle::create_subprocess("[...]/cucumber-pickle-runner");
  auto subprocess = std::get<pickle::Subprocess>(result);

  auto & get_runner().run(subprocess);
  */
}

} // namespace cucumber
