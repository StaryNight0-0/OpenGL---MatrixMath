
# --------------------CMAKE SETUP -----------------------------

cmake_minimum_required(VERSION 3.28 FATAL_ERROR)
project("Caboodle")

set(CMAKE_CXX_STANDARD          20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS        OFF)

find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)


# ---------------------------------------------------------------

add_library(main STATIC
         src/Project/Window.cpp
         src/Project/MainLoop.cpp
)

target_include_directories(main PUBLIC src)
target_link_libraries(main PRIVATE SDL2::SDL2  PRIVATE glad)


add_library(graphics STATIC
         src/Graphics/Shaders.cpp)
target_include_directories(graphics PUBLIC src)
target_link_libraries(graphics PRIVATE SDL2::SDL2 PRIVATE glad)





# -----------------------------------------------------------------------------




add_executable(${PROJECT_NAME} src/Caboodle/Caboodle.cpp)

add_subdirectory(OpenGL/glad)


target_include_directories(${PROJECT_NAME} PRIVATE src)

target_link_libraries(${PROJECT_NAME} PRIVATE
     SDL2::SDL2
     glad
     main
     graphics
     )

add_custom_command(TARGET Caboodle POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory 
${CMAKE_SOURCE_DIR}/src/Graphics $<TARGET_FILE_DIR:Caboodle>/Graphics)


# --------------------------------------------------------------
