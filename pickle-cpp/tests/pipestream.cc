#include <catch2/catch.hpp>

#include "pipestream.h"

#include <unistd.h>

#include <thread>

TEST_CASE("data written to a pipe stream should end up in the to pipe", "pipestream") {
  int from[2];
  int to[2];
  REQUIRE(::pipe(from) == 0);
  REQUIRE(::pipe(to) == 0);

  std::string const some_data = "some data";

  std::thread test_thread{[&]{
    pickle::PipeStream testee{to[1], from[0]};
    testee << some_data;
  }};

  std::array<char, 100> buffer{};
  auto const bytes_read = ::read(to[0], buffer.data(), buffer.size());
  REQUIRE(bytes_read == some_data.size());
  REQUIRE(std::string(buffer.begin(), buffer.begin() + bytes_read) == some_data);

  test_thread.join();
}
