
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
GLuint gVertexArray = 0;
GLuint gVertexBuffer = 0;

bool Quit = false;


void OpenGL(){
	std::cout << "Vendor" << glGetString(GL_VENDOR) << std::endl;
	std::cout << "Renderer: " << glGetString(GL_RENDERER);
}


//-------------------------------------------------------------------------------------------------------------------------------------



void VertexSpecification(){

	const std::vector<GLfloat> vertexPosition{

		-0.8f,-0.8f,0.0f, //Vertex 1
		0.8f, -0.8f,0.0f, //Vertex 2
		0.0f, 0.8f, 0.0f  //Vertex 3
	};
        
	
	glGenVertexArrays(1,&gVertexArray);
	glBindVertexArray(gVertexArray);

	glGenBuffers(1,&gVertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, gVertexBuffer);
	glBufferData(GL_ARRAY_BUFFER,vertexPosition.size() * sizeof(GLfloat), vertexPosition.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glBindVertexArray(0);
	glDisableVertexAttribArray(0);
}







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

}

void Draw(){

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
VertexSpecification();
CreateGraphicsPipeline();
Loop();
Cleanup();




return 0;

}
