find_package(Threads)

add_library(pickle-cpp
  src/pickle.cc
  src/runner.cc
  src/step_definition.cc
  src/main.cc
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
  tests/runner.cc
  )

target_link_libraries(pickle-cpp-tests
  PRIVATE
    pickle::settings
    pickle::cpp
    catchorg::catch2
    Threads::Threads
  )

target_include_directories(pickle-cpp-tests
  PRIVATE src
  )

add_custom_target(run-pickle-cpp-tests ALL
  COMMAND pickle-cpp-tests
  )


