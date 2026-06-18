#include <iostream>
#include "MainLoop.h"
#include "glad/glad.h"







void MainLoop::preDraw(){

glDisable(GL_DEPTH_TEST);
glDisable(GL_CULL_FACE);

glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

glUseProgram(shader.PipelineShader);
glm::mat4 translate = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f,uOffset,0.0f));
GLint modelMatrixLocation = glGetUniformLocation(shader.PipelineShader,"u_ModelMatrix"); // can print this out if needed using cout
if(modelMatrixLocation >=0){
		glUniformMatrix4fv(modelMatrixLocation,1,GL_FALSE,&translate[0][0]);
	}
	else{
		std::cout << "Could not find model matrix" << std::endl;
		exit(EXIT_FAILURE);

	}
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

	if(state[SDL_SCANCODE_ESCAPE]){
		quit = true;
	}
	if(state[SDL_SCANCODE_UP]){
		uOffset += 0.01f;
		std::cout << "Offset: " << uOffset << std::endl;
	}
	if(state[SDL_SCANCODE_DOWN]){
		uOffset -= 0.01f;
		std::cout << "Offset: " << uOffset << std::endl;

	}

}       


