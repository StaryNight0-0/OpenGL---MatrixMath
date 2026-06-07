cmake_minimum_required(VERSION 3.28)
project(Caboodle)

find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)
