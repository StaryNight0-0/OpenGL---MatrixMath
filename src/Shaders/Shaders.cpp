#include <iostream>
#include <glad/glad.h>
#include "Shaders.h"
#include <vector>

GLuint Shaders::compileShader(GLuint type , const std::string &source){

GLuint shaderObject;

if(type == GL_VERTEX_SHADER){
       shaderObject = glCreateShader(GL_VERTEX_SHADER);
	}
else if(type == GL_FRAGMENT_SHADER){
       shaderObject = glCreateShader(GL_FRAGMENT_SHADER);
	}

const char* src = source.c_str();	
glShaderSource(shaderObject, 1, &src, NULL);
glCompileShader(shaderObject);
	

return shaderObject;
}


GLuint Shaders::CreateShader(const std::string &VertexShader, const std::string &FragmentShader){

GLuint Object = glCreateProgram();
GLuint myVertexShader = compileShader(GL_VERTEX_SHADER, gVertexShaderSource);
GLuint myFragmentShader = compileShader(GL_FRAGMENT_SHADER, gFragmentShaderSource);

glAttachShader(Object, myVertexShader);
glAttachShader(Object, myFragmentShader);
glLinkProgram(Object);
glValidateProgram(Object);
glDeleteShader(myVertexShader);
glDeleteShader(myFragmentShader);

return Object;
}

void Shaders::CreateGraphicsPipeline(){

gPipelineShader = CreateShader(gVertexShaderSource, gFragmentShaderSource);

}

void Shaders::VertexSpec(){

	const std::vector<GLfloat> vertexPosition{

		-0.8f,-0.8f,0.0f, //Vertex 1
		0.8f, -0.8f,0.0f, //Vertex 2
		0.0f, 0.8f, 0.0f  //Vertex 3
	};
        
	
	glGenVertexArrays(1,&gVertexArray);
	glBindVertexArray(gVertexArray);

	glGenBuffers(1,&gVertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, gVertexBuffer);
	glBufferData(GL_ARRAY_BUFFER,sizeof(vertexPosition), vertexPosition.data(), GL_STATIC_DRAW);

	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
	glDisableVertexAttribArray(0);
}


void Shaders::OpenGLInfo(){

std::cout << "Vendor" << glGetString(GL_VENDOR) << std::endl;
std::cout << "Renderer: " << glGetString(GL_RENDERER);

}

