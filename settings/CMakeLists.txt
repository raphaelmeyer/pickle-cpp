add_library(settings INTERFACE)
add_library(pickle::settings ALIAS settings)

target_compile_features(settings
  INTERFACE
    cxx_std_17
  )

target_compile_options(settings
  INTERFACE
    "-Wall"
    "-Werror"
  )
