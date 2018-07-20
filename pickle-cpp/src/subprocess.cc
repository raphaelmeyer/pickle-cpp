#include "subprocess.h"

#include "error.h"

namespace pickle {

std::variant<subprocess, Error> create_subprocess(std::string const & path) {
  return subprocess{};
};

} // namespace pickle
