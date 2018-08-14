find_package(Threads)

add_library(pickle-cpp
  src/engine.cc
  src/subprocess.cc
  src/cucumber.cc
  src/pickle.cc
  src/runner.cc
  src/pipestream.cc
  )
add_library(pickle::cpp ALIAS pickle-cpp)

target_link_libraries(pickle-cpp
  PRIVATE
    pickle::settings
    nlohmann::json
  )

target_include_directories(pickle-cpp
  PUBLIC include
  )


add_executable(pickle-cpp-tests
  tests/main.cc
  tests/subprocess.cc
  tests/runner.cc
  tests/pipestream.cc
  )

target_link_libraries(pickle-cpp-tests
  PRIVATE
    pickle::cpp
    pickle::settings
    catchorg::catch2
    Threads::Threads
  )

target_include_directories(pickle-cpp-tests
  PRIVATE src
  )

add_custom_target(run-pickle-cpp-tests ALL
  COMMAND pickle-cpp-tests
  DEPENDS subprocess_stub
  )

add_executable(subprocess_stub
  tests/subprocess_stub.cc
  )
