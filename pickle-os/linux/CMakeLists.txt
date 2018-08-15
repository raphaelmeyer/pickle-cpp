add_library(pickle-linux
  src/pipestream.cc
  src/forkexec.cc
  )
add_library(pickle::linux ALIAS pickle-linux)

target_include_directories(pickle-linux
  PUBLIC
    include
  )

target_link_libraries(pickle-linux
  PRIVATE
    pickle::settings
    pickle::os-interface
  )

add_executable(pickle-linux-tests
  tests/main.cc
  tests/pipestream.cc
  tests/subprocess.cc
  )

target_include_directories(pickle-linux-tests
  PRIVATE
    src
  )

target_link_libraries(pickle-linux-tests
  PRIVATE
    pickle::settings
    pickle::linux
    pickle::os
    catchorg::catch2
  )

add_custom_target(run-pickle-linux-tests ALL
  COMMAND pickle-linux-tests
  DEPENDS subprocess_stub
  )

add_executable(subprocess_stub
  tests/subprocess_stub.cc
  )
