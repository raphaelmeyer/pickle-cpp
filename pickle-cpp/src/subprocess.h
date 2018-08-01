#pragma once

#include <iostream>
#include <sstream>
#include <variant>

namespace pickle {

struct Error;

class Subprocess {
public:
  std::iostream & io();

private:
  std::stringstream _io;
};

std::variant<Error, Subprocess> create_subprocess(std::string const & path);

} // namespace pickle
