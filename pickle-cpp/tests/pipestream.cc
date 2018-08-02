#include <catch2/catch.hpp>

#include "pipestream.h"

#include <unistd.h>

/*
TEST_CASE("data written to a pipe stream should end up in the to pipe", "pipestream") {
  int from[2];
  int to[2];
  REQUIRE(::pipe(from) == 0);
  REQUIRE(::pipe(to) == 0);

  pickle::PipeStream testee{to[0], from[1]};
  testee << "some data";

  char buffer[100];
  ::read(to[1], buffer, 100);
  REQUIRE(std::string(buffer) == "some data");
}
*/
