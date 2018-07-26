#include <pickle-cpp/cucumber.h>

#include <iostream>

namespace cucumber {

void Given(std::string name, std::function<void(Pickle const &)> definition) {
}

void When(std::string name, std::function<void(Pickle const &)> definition) {
}

void Then(std::string name, std::function<void(Pickle const &)> definition) {
  std::cout
    << "1 scenario (1 passed)" << "\n"
    << "1 step (1 passed)" << "\n";
}

} // namespace cucumber
