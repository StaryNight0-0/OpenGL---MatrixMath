#include <iostream>
#include "MainLoop.h"
#include "glad/glad.h"
#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_opengl3.h>
#include <imgui.h>
#include <string>



void MainLoop::imgui(){

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();


           static float f = 0.0f;
            static int counter = 0;

            ImGui::Begin("Caboodle", &quit, ImGuiWindowFlags_MenuBar); // Create a window called "Hello, world!" and append into it.
	    if(ImGui::BeginMenuBar()){
		if(ImGui::BeginMenu("Options")){
			if(ImGui::MenuItem("Exit")){
				std::cout << "You have quit the engine" << std::endl;
				quit = true;
			}
			ImGui::EndMenu();
		}
		ImGui::EndMenuBar();
	}

            ImGui::Text("Cube is big and small ");               // Display some text (you can use a format strings too)

            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
            if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);

            ImGui::End();

}



void MainLoop::preDraw(){






glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


glViewport(0,0,win.screenWidth,win.screenHeight);
glEnable(GL_DEPTH_TEST);
glDepthFunc(GL_LESS);
glDisable(GL_CULL_FACE);

glUseProgram(shader.PipelineShader);



GLint modelMatrixLocation = glGetUniformLocation(shader.PipelineShader,"u_Model");
	if(modelMatrixLocation >= 0){
		glUniformMatrix4fv(modelMatrixLocation,1,GL_FALSE,&model[0][0]);
	}
	else{
		std::cout << "Could not find model matrix" << std::endl;
	}


model = glm::rotate(model,glm::radians(rotation), glm::vec3(0.0f,1.0f,0.0f));
float currentTime = SDL_GetTicks();
if(currentTime - lastTime >= + 1000){
		rotation += 0.05f;
		lastTime = currentTime;
	}


glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(uOffsetX,0.0f,uOffsetZ));
GLint viewMatrixLocation = glGetUniformLocation(shader.PipelineShader,"u_View"); // can print this out if needed using cout
if(viewMatrixLocation >=0){
		glUniformMatrix4fv(viewMatrixLocation,1,GL_FALSE,&view[0][0]);
	}
	else{
		std::cout << "Could not find view matrix" << std::endl;
		exit(EXIT_FAILURE);

	}


glm::mat4 perspective = glm::perspective(glm::radians(45.0f), (float)win.screenWidth / (float)win.screenHeight, 0.1f, 10.0f);
GLint perspectiveLocation = glGetUniformLocation(shader.PipelineShader, "u_Perspective");
	if(perspectiveLocation >=0){
		glUniformMatrix4fv(perspectiveLocation, 1, GL_FALSE, &perspective[0][0]);
	}
	else{
		std::cout << "Could not find perspective uniform variable" << std::endl;
		exit(EXIT_FAILURE);
	}


}


void MainLoop::draw(){


glBindVertexArray(shader.VertexArray);
glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, shader.ElementVertexBuffer);
glDrawElements(GL_TRIANGLES,36,GL_UNSIGNED_INT,0);
glBindVertexArray(0);
ImGui::Render();
ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
SDL_GL_SwapWindow(win.window);
}

void MainLoop::loop(){
        win.init();
	shader.OpenGLInfo();
	shader.VertexSpec();
	shader.CreateGraphicsPipeline();
	
	

	while(!quit){
		SDL_Delay(16);
		Input();
		imgui();
		preDraw();
		draw();
	}

	win.cleanup();
}


void MainLoop::Input(){

while(SDL_PollEvent(&event) != 0){
              ImGui_ImplSDL2_ProcessEvent(&event);


		if(event.type == SDL_QUIT){
			std::cout << "Quitting" << std::endl;
			quit = true;
		}
	}

	if(state[SDL_SCANCODE_ESCAPE]){
		quit = true;
	}
	if(state[SDL_SCANCODE_UP]){
		uOffsetZ += 0.01f;
		std::cout << "Offset on z: " << uOffsetZ << std::endl;
	}
	if(state[SDL_SCANCODE_DOWN]){
		uOffsetZ -= 0.01f;
		std::cout << "Offset on z: " << uOffsetZ << std::endl;

	}
	if(state[SDL_SCANCODE_LEFT]){
		uOffsetX -= 0.01f;
		std::cout << "Offset on x: " << uOffsetX << std::endl;
	}
	if(state[SDL_SCANCODE_RIGHT]){
		uOffsetX += 0.01f;
		std::cout << "Offset on x: " << uOffsetX << std::endl;
	}

}  







