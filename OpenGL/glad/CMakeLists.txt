cmake_minimum_required(VERSION 3.2.8)
project(Caboodle)

add_library(glad STATIC include/glad/glad.h src/glad.c)
target_include_directories(glad PUBLIC include/)
