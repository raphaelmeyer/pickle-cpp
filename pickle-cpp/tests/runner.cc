#include <catch2/catch.hpp>

#include "runner.h"

#include <sstream>

TEST_CASE("runner should send a start command right after starting", "runner") {
  std::stringstream pickle_runner{};

  pickle::Runner testee{};
  testee.run(pickle_runner);

  auto const expected = R"json({ "type": "start" }
)json";

  REQUIRE(pickle_runner.str() == expected);
}
