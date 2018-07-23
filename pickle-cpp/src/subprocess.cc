#include "subprocess.h"

#include "error.h"

namespace pickle {

std::variant<Error, subprocess> create_subprocess(std::string const & path) {
  if(path == "./subprocess") {
    return subprocess{};
  }
  return {};
};

} // namespace pickle
