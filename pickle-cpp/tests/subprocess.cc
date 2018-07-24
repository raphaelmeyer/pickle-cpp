#include <catch2/catch.hpp>

#include "error.h"
#include "subprocess.h"

TEST_CASE("create_subprocess should return an object to interact with the subprocess", "subprocess") {
  auto result = pickle::create_subprocess("./subprocess");

  REQUIRE(std::get_if<pickle::Subprocess>(&result) != nullptr);
}

TEST_CASE("create_subprocess should return an error if the executable does not exist", "subprocess") {
  auto result = pickle::create_subprocess("invalid path");

  REQUIRE(std::get_if<pickle::Error>(&result) != nullptr);
}
