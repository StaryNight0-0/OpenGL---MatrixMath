#pragma once
#include <iostream>
#include <glad/glad.h>
#include <SDL2/SDL.h>
#include<SDL_opengl.h>







class Window{

public:

GLuint screenHeight = 0;
GLuint screenWidth = 0;
SDL_Window* window = nullptr;
SDL_GLContext OpenGLContext = nullptr;
const char* glsl_version = "#version 330";


void init();
void cleanup();

};
