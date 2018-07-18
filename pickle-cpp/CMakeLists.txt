add_executable(pickle-cpp
  src/main.cc
  src/engine.cc

  src/engine.h
  src/error.h
  )

target_compile_features(pickle-cpp PRIVATE cxx_std_17)
