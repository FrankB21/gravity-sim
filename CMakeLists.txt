cmake_minimum_required(VERSION 3.10)

project(collision_sim CXX)
set(CXX_STANDARD_REQUIRED CXX_17)

set(CS_SOURCES "src/main.cpp")
add_executable(collision_sim ${CS_SOURCES})

add_subdirectory("vendor/spdlog")
target_link_libraries(collision_sim PUBLIC spdlog)
target_link_libraries(collision_sim PUBLIC "sfml-graphics")
target_link_libraries(collision_sim PUBLIC "sfml-window")
target_link_libraries(collision_sim PUBLIC "sfml-system")

target_include_directories(collision_sim PUBLIC "vendor/spdlog/include")
