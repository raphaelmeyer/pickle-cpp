#include <catch2/catch.hpp>

#include "subprocess.h"
#include "error.h"

TEST_CASE("create_subprocess should return an object to interact with the subprocess", "subprocess") {
  auto result = pickle::create_subprocess("./subprocess");

  REQUIRE(std::get_if<pickle::subprocess>(&result) != nullptr);
}

TEST_CASE("create_subprocess should return an error if the executable does not exist", "subprocess") {
  auto result = pickle::create_subprocess("invalid path");

  REQUIRE(std::get_if<pickle::Error>(&result) != nullptr);
}
