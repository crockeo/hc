cmake_minimum_required(VERSION 2.8)
project(hc)

# Setting output paths.
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/build/bin")
set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/build/lib")

# Setting the C++ 11 flag.
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

# Actually setting up the executable.
add_executable(hc src/main.cpp)
