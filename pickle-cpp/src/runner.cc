#include "runner.h"

namespace pickle {

void Runner::run(std::iostream & pickle_runner) {
  pickle_runner << R"json({ "type": "start" }
)json";
}

} // namespace pickle
