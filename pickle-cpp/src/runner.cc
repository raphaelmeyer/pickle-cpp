#include "runner.h"

#include <nlohmann/json.hpp>

namespace pickle {

Runner::Runner(std::string feature_path) : _feature_path(std::move(feature_path)) {
}

void Runner::run(std::iostream & pickle_runner) {
  using namespace nlohmann;
  auto start = R"({
    "type": "start",
    "featuresConfig": {
      "filters": {},
      "order": {}
    },
    "runtimeConfig": {},
    "supportCodeConfig": {}
})"_json;

  start["featuresConfig"]["absolutePaths"] = {_feature_path};

  pickle_runner << start;
}

} // namespace pickle
