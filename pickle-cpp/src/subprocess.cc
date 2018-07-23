#include "subprocess.h"

#include "error.h"

namespace pickle {

std::variant<Error, Subprocess> create_subprocess(std::string const & path) {
  if(path == "./subprocess") {
    return Subprocess{};
  }
  return {};
};

} // namespace pickle
