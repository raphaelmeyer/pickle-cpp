add_executable(pickle-cpp
  src/main.cc
  src/engine.cc

  src/engine.h
  src/error.h
  )

target_compile_features(pickle-cpp PRIVATE cxx_std_17)

target_link_libraries(pickle-cpp
  PRIVATE nlohmann::json
  )

add_executable(pickle-cpp-tests
  tests/main.cc
  )

target_link_libraries(pickle-cpp-tests
  PRIVATE catchorg::catch2
  )

add_custom_target(run-pickle-cpp-tests ALL COMMAND pickle-cpp-tests)
