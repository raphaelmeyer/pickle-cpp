#include "runner.h"

#include <nlohmann/json.hpp>

namespace pickle {

void Runner::run(std::iostream & pickle_runner) {
  using namespace nlohmann;
  pickle_runner << R"({
    "type": "start",
    "featuresConfig": {
      "filters": {}
    }
})"_json;
}

} // namespace pickle
