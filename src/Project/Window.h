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
bool fullscreen, resizable;


void init();
void cleanup();

void set_title(const std::string title);
void set_size(int width, int height);
void set_fullscreen(bool state);
void set_resizable(bool state)


};
