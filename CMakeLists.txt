
# --------------------CMAKE SETUP -----------------------------

cmake_minimum_required(VERSION 3.28 FATAL_ERROR)
project("Caboodle")

set(CMAKE_CXX STANDARD          20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS        OFF)

find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)


# ---------------------------------------------------------------








# -----------------------------------------------------------------------------




add_executable(${PROJECT_NAME} src/Caboodle/Caboodle.cpp)

add_subdirectory(OpenGL/glad)
target_link_libraries(${PROJECT_NAME} PRIVATE glad)

target_include_directories(${PROJECT_NAME} PRIVATE src)

target_link_libraries(${PROJECT_NAME} PRIVATE
     SDL2::SDL2  
     )


# --------------------------------------------------------------
