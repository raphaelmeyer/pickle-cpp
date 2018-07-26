
add_custom_target(run-features ALL
  COMMAND bundler exec cucumber --version
  DEPENDS cucumber-ruby)

add_custom_target(cucumber-ruby
  COMMAND bundler install --path gems
  DEPENDS Gemfile Gemfile.lock
  )

add_custom_command(
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/bundler/Gemfile Gemfile
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/bundler/Gemfile.lock Gemfile.lock
  OUTPUT Gemfile Gemfile.lock
  DEPENDS bundler/Gemfile bundler/Gemfile.lock
  )


add_executable(example-pickle
  example-pickle/main.cc
  )

target_link_libraries(example-pickle
  PRIVATE pickle-cpp
  )
