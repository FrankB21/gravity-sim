cmake_minimum_required(VERSION 3.10)

project(collision_sim CXX)
set(CXX_STANDARD_REQUIRED CXX_17)

add_subdirectory("vendor/spdlog")
target_link_libraries(spdlog)

set(CS_SOURCES "src/main.cpp")
add_executable(collision_sim ${CS_SOURCES})

target_include_directories(collision_sim PUBLIC "vendor/spdlog/include")
