cmake_minimum_required(VERSION 3.2.8)
project(Caboodle)

add_library(imgui STATIC src/imgui.cpp
                         src/imgui_demo.cpp
                         src/imgui_draw.cpp
                         src/imgui_impl_opengl3.cpp
                         src/imgui_impl_sdl2.cpp
                         src/imgui_tables.cpp
                         src/imgui_widgets.cpp)
target_include_directories(imgui PUBLIC include/)
