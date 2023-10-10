cmake_minimum_required(VERSION 3.26)
project(part01 C)

set(CMAKE_C_STANDARD 11)

add_executable(part01 src/main.c
        src/lexer.c)
