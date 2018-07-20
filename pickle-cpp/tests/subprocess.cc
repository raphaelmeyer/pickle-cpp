#include <catch2/catch.hpp>

#include "subprocess.h"
#include "error.h"

TEST_CASE("should return a handle to the subprocess", "subprocess") {

  auto result = pickle::create_subprocess("./subproces");

  REQUIRE(std::get_if<pickle::subprocess>(&result) != nullptr);
}

