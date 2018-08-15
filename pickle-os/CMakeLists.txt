add_subdirectory(interface)
add_subdirectory(linux)

add_library(pickle-os INTERFACE)
add_library(pickle::os ALIAS pickle-os)

target_link_libraries(pickle-os
  INTERFACE
    pickle::os-interface
    pickle::linux
  )
