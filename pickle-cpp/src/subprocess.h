#pragma once

#include <iostream>
#include <variant>

namespace pickle {

struct Error;

class Subprocess {
public:
};

std::variant<Error, Subprocess> create_subprocess(std::string const & path);

} // namespace pickle
