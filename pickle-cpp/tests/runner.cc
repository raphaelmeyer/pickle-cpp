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

TEST_CASE("start command should contain a featuresConfig section", "runner") {
  std::stringstream pickle_runner{};

  pickle::Runner testee{};
  testee.run(pickle_runner);

  auto const actual = nlohmann::json::parse(pickle_runner.str());

  auto config = actual.find("featuresConfig");
  REQUIRE(config != actual.end());
  REQUIRE(config->find("filters") != config->end());
  REQUIRE(config->find("order") != config->end());
}

TEST_CASE("start command should contain a supportCodeConfig section", "runner") {
  std::stringstream pickle_runner{};

  pickle::Runner testee{};
  testee.run(pickle_runner);

  auto const actual = nlohmann::json::parse(pickle_runner.str());

  auto config = actual.find("supportCodeConfig");
  REQUIRE(config != actual.end());
}

TEST_CASE("start command should contain a runtimeConfig section", "runner") {
  std::stringstream pickle_runner{};

  pickle::Runner testee{};
  testee.run(pickle_runner);

  auto const actual = nlohmann::json::parse(pickle_runner.str());

  auto config = actual.find("runtimeConfig");
  REQUIRE(config != actual.end());
}
