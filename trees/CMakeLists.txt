cmake_minimum_required(VERSION 3.31)
project(trees C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(trees
        helpers.c
        main.c
        traverse.c
        tree.c
        queue.c
        queue.h
)
