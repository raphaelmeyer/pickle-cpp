#include <catch2/catch.hpp>

#include <nlohmann/json.hpp>

#include "runner.h"

#include <sstream>

TEST_CASE("runner should send a start command right after starting", "runner") {
  std::stringstream pickle_runner{};

  pickle::Runner testee{};
  testee.run(pickle_runner);

  auto const actual = nlohmann::json::parse(pickle_runner.str());
  REQUIRE(actual["type"] == "start");
}
