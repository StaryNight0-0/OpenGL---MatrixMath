#include <iostream>
#include <glad/glad.h>
#include "Window.h"
#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_opengl3.h>



void Window::init(){

	std::cout << "Please input a width for your window: " << std::endl;
	std::cin >> screenWidth;
	std::cout << "Please input a height for your window: " << std::endl;    // Asks the user to input a width and height for their window
	std::cin >> screenHeight;

	if(screenWidth > 1920){
		std::cout << "Please choose a lower resolution" << std::endl;
		exit(EXIT_FAILURE);
	}
	else if(screenHeight > 1080){
		std::cout << "Please choose a lower resolution" << std::endl;
		exit(EXIT_FAILURE);
	}

if(SDL_Init(SDL_INIT_VIDEO) < 0){
	std::cout << "Window could not be initiallized: " << SDL_GetError();
	exit(1);
	}

SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
float main_scale = ImGui_ImplSDL2_GetContentScaleForDisplay(0);

window = SDL_CreateWindow("Caboodle",0,0,screenWidth * main_scale,screenHeight * main_scale,SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE );
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

///// IMGUI FUNCTIONS 
IMGUI_CHECKVERSION();
ImGui::CreateContext();
ImGuiIO& io = ImGui::GetIO(); (void)io;
io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  
ImGui::StyleColorsDark();

ImGuiStyle& style = ImGui::GetStyle();
style.ScaleAllSizes(main_scale);
style.FontScaleDpi = main_scale;

ImGui_ImplSDL2_InitForOpenGL(window, OpenGLContext);
ImGui_ImplOpenGL3_Init(glsl_version);
	


std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

}

void Window::cleanup(){

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();

        SDL_GL_DeleteContext(OpenGLContext);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
