#include <iostream>
#include "MainLoop.h"
#include "glad/glad.h"
#include "Window.h"

Window win;



//void MainLoop::preDraw(){

//glDisable(GL_DEPTH_TEST);
//glDisable(GL_CULL_FACE);

//glViewport(0,0,win.screenWidth,win.screenHeight);
//glClearColor(1.f,1.f,0.f,1.f);

//glUseProgram(gPipelineShader);	

//}


//void MainLoop::draw(){

//glBindVertexArray(gVertexArray);
//glBindBuffer(GL_ARRAY_BUFFER, gVertexBuffer);

//glDrawArrays(GL_TRIANGLES,0,3);
//}


void MainLoop::loop(){

	while(!quit){
		Input();
		//preDraw();
	//	draw();

		glClearColor(0.7f, 0.9f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		SDL_GL_SwapWindow(win.window);
		SDL_Delay(1);
	}	
}


void MainLoop::Input(){

while(SDL_PollEvent(&event) != 0){
		if(event.type == SDL_QUIT){
			std::cout << "Quitting" << std::endl;
			quit = true;
		}
	}
}
