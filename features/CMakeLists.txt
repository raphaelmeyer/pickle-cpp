
add_custom_target(run-features ALL
  COMMAND bundler exec cucumber --require ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR} --wip --tags @wip:2
  DEPENDS cucumber-ruby example-pickle
  )

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
  example-pickle/steps.cc
  )

target_link_libraries(example-pickle
  PRIVATE
    pickle::cpp
    pickle::main
    pickle::settings
  )
