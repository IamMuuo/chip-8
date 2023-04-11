cmake_minimum_required(VERSION 3.7)

project(CHIP8)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(CHIP8 main.cpp)
target_link_libraries(CHIP8 ${SDL2_LIBRARIES})
