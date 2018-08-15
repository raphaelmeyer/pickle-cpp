#pragma once

#include <string>

namespace pickle {

struct OSError {
  std::string const what;
};

} // namespace pickle
