#  Copyright 2020 Franco Berni

#  Licensed under the Apache License, Version 2.0 (the "License");
#  you may not use this file except in compliance with the License.
#  You may obtain a copy of the License at

#      http://www.apache.org/licenses/LICENSE-2.0

#  Unless required by applicable law or agreed to in writing, software
#  distributed under the License is distributed on an "AS IS" BASIS,
#  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#  See the License for the specific language governing permissions and
#  limitations under the License.

cmake_minimum_required(VERSION 3.10)

project(gravity_sim CXX)
set(CXX_STANDARD CXX_17)
set(CXX_STANDARD_REQUIRED ON)

set(GS_SOURCES
    "${CMAKE_SOURCE_DIR}/src/main.cpp"
    "${CMAKE_SOURCE_DIR}/src/DisplayManager.cpp"
)
add_executable(gravity_sim ${GS_SOURCES})

include_directories("${CMAKE_SOURCE_DIR}/include")

add_subdirectory("vendor/spdlog")
target_link_libraries(gravity_sim PUBLIC spdlog)
add_subdirectory("vendor/glm")
target_link_libraries(gravity_sim PUBLIC glm)

target_link_libraries(gravity_sim PUBLIC "sfml-graphics")
target_link_libraries(gravity_sim PUBLIC "sfml-window")
target_link_libraries(gravity_sim PUBLIC "sfml-system")

target_include_directories(gravity_sim PUBLIC "${CMAKE_SOURCE_DIR}/vendor/spdlog/include")
target_include_directories(gravity_sim PUBLIC "${CMAKE_SOURCE_DIR}/vendor/glm/glm")
