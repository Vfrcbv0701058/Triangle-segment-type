cmake_minimum_required(VERSION 3.26)
project(Project_1)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES main.cpp
        src/geometry.cpp
        include/geometry.hpp
        test/test.cpp)
add_subdirectory(lib/googletest/)

add_executable(Project_1 ${SOURCE_FILES})
include_directories(lib/googletest/googletest/include)
target_link_libraries(Project_1 gtest)

