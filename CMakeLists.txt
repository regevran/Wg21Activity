cmake_minimum_required(VERSION 3.20)
project(DockerDevEnv)

set(CMAKE_CXX_STANDARD 20)

add_executable(DockerDevEnv docker_dev_env.cpp)

# Add the directory containing catch.hpp to the include paths
target_include_directories(DockerDevEnv PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})