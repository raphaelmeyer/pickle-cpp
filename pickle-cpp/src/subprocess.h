#pragma once

#include <variant>
#include <iostream>

namespace pickle {

struct Error;

class subprocess {
public:
};

std::variant<Error, subprocess> create_subprocess(std::string const & path);

} // namespace pickle
