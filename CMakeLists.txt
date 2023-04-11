# Project Chip 8
# Author Erick Muuo
# (C) Copyright 2023 All rights reserved

cmake_minimum_required(VERSION 3.7)

project(CHIP8)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_library(chip8-core chip8/chip8.cpp)

add_executable(chip8 main.cpp)

target_link_libraries(chip8 chip8-core)
target_link_libraries(chip8 ${SDL2_LIBRARIES})
