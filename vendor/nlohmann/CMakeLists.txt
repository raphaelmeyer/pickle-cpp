add_library(json INTERFACE)
add_library(nlohmann::json ALIAS json)

target_include_directories(json INTERFACE include)
