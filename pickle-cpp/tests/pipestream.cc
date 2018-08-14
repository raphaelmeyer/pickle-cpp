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

  test_thread.join();

  std::array<char, 100> buffer{};
  auto const bytes_read = ::read(to[0], buffer.data(), buffer.size());
  ::close(to[0]);

  REQUIRE(bytes_read == some_data.size());
  REQUIRE(std::string(buffer.begin(), buffer.begin() + bytes_read) == some_data);
}

TEST_CASE("data in the pipe should be readable from a pipe stream", "pipestream") {
  int from[2];
  int to[2];
  REQUIRE(::pipe(from) == 0);
  REQUIRE(::pipe(to) == 0);

  std::string const data = "some arbitrary data";
  std::string actual;

  ::write(from[1], data.data(), data.size());
  ::close(from[1]);

  std::thread test_thread{[&]{
    pickle::PipeStream testee{to[1], from[0]};
    std::getline(testee, actual);
  }};

  test_thread.join();

  REQUIRE(actual.size() == data.size());
  REQUIRE(actual == data);
}
