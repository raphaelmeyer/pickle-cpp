#include "engine.h"
#include "error.h"

#include <string>
#include <variant>

int main() {

  auto result = pickle::start_engine();
  if(auto error = std::get_if<pickle::Error>(&result)) {
    std::cerr << error->what << std::endl;
    return 1;
  }

  std::string const start{R"json({ "type": "start", "featuresConfig": { "filters": { "tagExpression": "" }, "order": {} }, "runtimeConfig": { "maxParallel": 1 }, "supportCodeConfig": {}, "stepDefinitions": [] }
)json"};

  auto & engine = std::get<std::iostream>(result);
  engine << start << std::endl;
}

