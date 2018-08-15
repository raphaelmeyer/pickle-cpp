#include <pickle-cpp/cucumber.h>

namespace cucumber
{

Step::Step(std::string name, std::function<void(cucumber::Pickle const &)> definition) {
}

Define::Define(std::initializer_list <cucumber::Step>) {
}

} // namespace cucumber
