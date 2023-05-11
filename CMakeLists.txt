cmake_minimum_required(VERSION 3.20)
project(ThreeWayComp)

set(CMAKE_CXX_STANDARD 20)

add_executable(ThreeWayComp  "3way.hpp" "tests/compilation_error.cpp" "tests/containers.cpp" "tests/ranges.cpp" "tests/t1.cpp" "tests/unordered.cpp" "tests/general_tests.cpp")

# Add the directory containing catch.hpp to the include paths
target_include_directories(ThreeWayComp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})