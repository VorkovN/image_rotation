cmake_minimum_required(VERSION 3.17)
project(image_rotation C)

set(CMAKE_C_STANDARD 11)
set(SRC main.c src/image.c src/bmp.c src/util.c)

include_directories(${CMAKE_CURRENT_LIST_DIR})
include_directories(${CMAKE_CURRENT_LIST_DIR}/include/)

add_executable(image_rotation ${SRC})