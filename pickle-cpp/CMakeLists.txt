add_library(pickle-cpp
  src/engine.cc
  src/subprocess.cc
  src/cucumber.cc
  src/pickle.cc
  src/runner.cc
  src/pipestream.cc
  )

target_compile_features(pickle-cpp PRIVATE cxx_std_17)

target_link_libraries(pickle-cpp
  PRIVATE nlohmann::json
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

target_compile_features(pickle-cpp-tests PRIVATE cxx_std_17)

target_link_libraries(pickle-cpp-tests
  PRIVATE pickle-cpp
  PRIVATE catchorg::catch2
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



# This is a spike, can be removed as soon as its insights are transformed into tests
add_executable(pickle-cpp-exe
  src/main.cc
  )

target_compile_features(pickle-cpp-exe PRIVATE cxx_std_17)

target_link_libraries(pickle-cpp-exe
  PRIVATE pickle-cpp
  )
