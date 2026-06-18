#include <iostream>
#include <glad/glad.h>
#include "Window.h"



void Window::init(){



if(SDL_Init(SDL_INIT_VIDEO) < 0){
	std::cout << "Window could not be initiallized: " << SDL_GetError();
	exit(1);
	}

SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);


window = SDL_CreateWindow("Caboodle",0,0,screenHeight,screenWidth,SDL_WINDOW_OPENGL);
if(window == nullptr ){
		std::cout << "SDL_CreateWindow has failed: " << SDL_GetError();
		exit(1);
	}

OpenGLContext = SDL_GL_CreateContext(window);
SDL_GL_MakeCurrent(window, OpenGLContext);
//SDL_GL_SetSwapInterval(1);
std::cout << SDL_GetCurrentVideoDriver() << std::endl;
if(OpenGLContext == nullptr){
		std::cout << "SDL_GL_CreateContext has failed: " << SDL_GetError();
		exit(1);
	}
if(!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)){
		std::cout << "GLAD init failed!" << std::endl;
	}

std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
glViewport(0,0,screenWidth,screenHeight);


}


void Window::cleanup(){
        SDL_GL_DeleteContext(OpenGLContext);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
