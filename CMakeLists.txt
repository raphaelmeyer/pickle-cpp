cmake_minimum_required(VERSION 3.10)
project(PickleCpp VERSION 0.0.1 LANGUAGES CXX)

if(NOT EXISTS "${CMAKE_BINARY_DIR}/cucumber-pickle-runner")
  file(DOWNLOAD https://github.com/cucumber/cucumber-pickle-runner/releases/download/v0.0.3/cucumber-pickle-runner-linux-amd64 "${CMAKE_BINARY_DIR}/download/cucumber-pickle-runner" SHOW_PROGRESS)
  file(COPY "${CMAKE_BINARY_DIR}/download/cucumber-pickle-runner" DESTINATION "${CMAKE_BINARY_DIR}"
    FILE_PERMISSIONS
      OWNER_EXECUTE OWNER_READ OWNER_WRITE
      GROUP_EXECUTE GROUP_READ
      WORLD_EXECUTE WORLD_READ
    )
endif()

