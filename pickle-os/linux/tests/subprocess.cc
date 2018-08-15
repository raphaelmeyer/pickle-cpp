#include <catch2/catch.hpp>

#include <pickle/os/oserror.h>
#include <pickle/os/subprocess.h>

TEST_CASE("create_subprocess should return an object to interact with the subprocess", "subprocess") {
  auto result = pickle::create_subprocess("./subprocess_stub");

  REQUIRE(std::get_if<std::shared_ptr<pickle::Subprocess>>(&result) != nullptr);
}

TEST_CASE("create_subprocess should return an error if the executable does not exist", "subprocess") {
  auto result = pickle::create_subprocess("invalid path");

  REQUIRE(std::get_if<pickle::OSError>(&result) != nullptr);
}

TEST_CASE("a Subprocess object should provide an iostream for the subprocess standard input and output", "subprocess") {
  auto result = pickle::create_subprocess("./subprocess_stub");
  auto subprocess = std::get<std::shared_ptr<pickle::Subprocess>>(result);

  auto & io = subprocess->io();
  io << "some input\n" << std::flush;

  std::string response;
  REQUIRE(std::getline(io, response));
  REQUIRE(response == "tupni emos");
}
