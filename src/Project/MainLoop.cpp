#include <iostream>
#include "MainLoop.h"
#include "glad/glad.h"





void MainLoop::preDraw(){

glDisable(GL_DEPTH_TEST);
glDisable(GL_CULL_FACE);

glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

glUseProgram(shader.PipelineShader);

}


void MainLoop::draw(){

glBindVertexArray(shader.VertexArray);
glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, shader.ElementVertexBuffer);
glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);



}



void MainLoop::loop(){

        win.init();
	shader.OpenGLInfo();
	shader.VertexSpec();
	shader.CreateGraphicsPipeline();
	
	
	

	while(!quit){
		
		Input();
		preDraw();
		draw();
		SDL_GL_SwapWindow(win.window);
	}

	win.cleanup();
}


void MainLoop::Input(){

while(SDL_PollEvent(&event) != 0){
		if(event.type == SDL_QUIT){
			std::cout << "Quitting" << std::endl;
			quit = true;
		}
	}
}
