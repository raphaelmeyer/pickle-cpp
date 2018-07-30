#pragma once

#include <pickle-cpp/pickle.h>

#include <functional>
#include <string>

namespace cucumber {

void Given(std::string name, std::function<void(Pickle const &)> definition);
void When(std::string name, std::function<void(Pickle const &)> definition);
void Then(std::string name, std::function<void(Pickle const &)> definition);

void run();

} // namespace cucumber
