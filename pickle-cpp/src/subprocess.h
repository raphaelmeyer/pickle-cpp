#pragma once

#include <variant>
#include <iostream>

namespace pickle {

struct Error;

class Subprocess {
public:
};

std::variant<Error, Subprocess> create_subprocess(std::string const & path);

} // namespace pickle
