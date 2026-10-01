cmake_minimum_required(VERSION 3.20)
project(yliu VERSION 1.0 LANGUAGES CXX)

# Force C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the executable and its source files
add_executable(yliu
    src/main.cpp
    src/vector.cpp
)

# Tell CMake where to look for header files (.h)
target_include_directories(yliu PRIVATE include)
