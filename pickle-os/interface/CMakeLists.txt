add_library(pickle-os-interface INTERFACE)
add_library(pickle::os-interface ALIAS pickle-os-interface)

target_include_directories(pickle-os-interface
  INTERFACE
    include
  )
