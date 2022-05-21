
cmake_minimum_required(VERSION 3.16)

project(P2022)

# add the executable
add_executable(p2022_ex1 example1.cpp)
add_executable(p2022_ex2 test_std_compare_func.cpp)

set_target_properties(
    p2022_ex1 p2022_ex2
    PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)

