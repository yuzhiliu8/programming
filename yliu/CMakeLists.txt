cmake_minimum_required(VERSION 3.20)
project(yliu VERSION 1.0 LANGUAGES CXX)

# Force C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(yliu INTERFACE)
target_include_directories(yliu INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_compile_features(yliu INTERFACE cxx_std_17)

include(CTest)
if(BUILD_TESTING)
    add_subdirectory(test)
endif()


add_executable(yliu_example src/main.cpp)
target_link_libraries(yliu_example PRIVATE yliu)
