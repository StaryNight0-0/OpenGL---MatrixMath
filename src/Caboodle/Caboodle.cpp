
#include <iostream>
#include <SDL2/SDL.h>
#include <glad/glad.h>
#include <cstdlib>
#include <vector>

int screenHeight = 640;
int screenWidth = 480;
SDL_Window* window = nullptr;
SDL_GLContext OpenGLContext = nullptr;
SDL_Event event;

bool Quit = false;

GLuint gPipelineShader = 0;


//---------------------------------------------------------Run Function------------------------------------------------------------------

void Run(){

if(SDL_Init(SDL_INIT_VIDEO) < 0){
		std::cout << "Window could not be initiallized: " << SDL_GetError();
		exit(1);
	}

SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);



window = SDL_CreateWindow("Caboodle",0,0,screenHeight,screenWidth,SDL_WINDOW_OPENGL);
if(window == nullptr ){
		std::cout << "SDL_CreateWindow has failed: " << SDL_GetError();
		exit(1);
	}

OpenGLContext = SDL_GL_CreateContext(window);
if(OpenGLContext == nullptr){
		std::cout << "SDL_GL_CreateContext has failed: " << SDL_GetError();
		exit(1);
	}

	

}

//---------------------------------------------------------Main Loop Functions-----------------------------------------------------------------

void Input(){
while(SDL_PollEvent(&event) != 0){
		if(event.type == SDL_QUIT){
			std::cout << "Quitting" << std::endl;
			Quit = true;
		}
	}

}

void PreDraw(){
glDisable(GL_DEPTH_TEST);
glDisable(GL_CULL_FACE);

glViewport(0,0,screenWidth,screenHeight);
glClearColor(1.f,1.f,0.f,1.f);

glUseProgram(gPipelineShader);
}

void Draw(){
glBindVertexArray(gVertexArray);
glBindBuffer(GL_ARRAY_BUFFER, gVertexBuffer);

glDrawArrays(GL_TRIANGLES,0,3);
}



void Loop(){

	while(!Quit){
		Input();
		PreDraw();
		Draw();
		SDL_GL_SwapWindow(window);
	}

}

//--------------------------------------------------------Cleanup Function-----------------------------------------------------------------

void Cleanup(){
	SDL_DestroyWindow(window);
	SDL_Quit();
}


int main(int argc, char* argv[]) {


Run();
Loop();
Cleanup();




return 0;

}
