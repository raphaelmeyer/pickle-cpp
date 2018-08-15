#pragma once

#include <pickle-cpp/pickle.h>

#include <functional>
#include <string>

namespace cucumber {

class Step {
public:
  Step(std::string name, std::function<void(Pickle const &)> definition);
};

class Define {
public:
  Define(std::initializer_list<Step>);
};

using Given = Step;
using When = Step;
using Then = Step;

} // namespace cucumber
