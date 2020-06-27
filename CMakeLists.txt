cmake_minimum_required(VERSION 3.10)

project(gravity_sim CXX)
set(CXX_STANDARD_REQUIRED CXX_17)

set(GS_SOURCES "src/main.cpp")
add_executable(gravity_sim ${CS_SOURCES})

add_subdirectory("vendor/spdlog")
target_link_libraries(gravity_sim PUBLIC spdlog)
target_link_libraries(gravity_sim PUBLIC "sfml-graphics")
target_link_libraries(gravity_sim PUBLIC "sfml-window")
target_link_libraries(gravity_sim PUBLIC "sfml-system")

target_include_directories(collision_sim PUBLIC "vendor/spdlog/include")
