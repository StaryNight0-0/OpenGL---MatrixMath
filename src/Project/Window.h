#pragma once
#include <iostream>
#include <glad/glad.h>
#include <SDL2/SDL.h>
#include<SDL_opengl.h>




class Window{

public:

GLuint screenHeight = 640;
GLuint screenWidth = 480;
SDL_Window* window = nullptr;
SDL_GLContext OpenGLContext = nullptr;	


void init();
void cleanup();

};
