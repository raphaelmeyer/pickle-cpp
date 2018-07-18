#pragma once

#include <iostream>
#include <variant>

namespace pickle {

struct Error;

std::variant<std::iostream, Error> start_engine();

} // namespace pickle
