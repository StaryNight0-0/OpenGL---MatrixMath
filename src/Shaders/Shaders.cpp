#include <iostream>
#include <glad/glad.h>
#include "Shaders.h"
#include <vector>
#include <string>
#include <fstream>



std::string Shaders::LoadShader(const std::string& filename){

	std::string result = "";
	std::string line = "";
	std::ifstream File(filename.c_str());

	if(File.is_open()){
		while(std::getline(File, line)){
			result += line + '\n';
		}
		File.close();
	}
return result;
}

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

GLint shaderCompiled = GL_FALSE;
glGetShaderiv(shaderObject, GL_COMPILE_STATUS, &shaderCompiled);

	if(shaderCompiled != GL_TRUE){
		std::cout << "Unable to complile shader: " << shaderObject << src << std::endl;
		//printShaderLog(shaderObject);
		glDeleteShader(shaderObject);
		shaderObject = 0;
	}
	else{
		std::cout << "Unable to open file: " << src << std::endl;
	}	

return shaderObject;
}


GLuint Shaders::CreateShader(const std::string &vertexShaderSource, const std::string &fragmentShaderSource){

GLuint Object = glCreateProgram();
GLuint myVertexShader = compileShader(GL_VERTEX_SHADER, vertexShaderSource);
GLuint myFragmentShader = compileShader(GL_FRAGMENT_SHADER,fragmentShaderSource);

glAttachShader(Object, myVertexShader);
glAttachShader(Object, myFragmentShader);
glLinkProgram(Object);
glValidateProgram(Object);
glDeleteShader(myVertexShader);
glDeleteShader(myFragmentShader);

return Object;
}

void Shaders::CreateGraphicsPipeline(){


PipelineShader = CreateShader(vertexShaderSource, fragmentShaderSource);

}

void Shaders::VertexSpec(){

	const std::vector<GLfloat> vertexInfo{

		0.5f, 0.4f,0.0f,         // top left
		1.0f, 0.0f, 0.0f,       // colour
		0.5f, -0.5f,0.0f,      //bottom right
		0.0f, 1.0f, 0.0f,     // colour
	        -0.5f, -0.5f, 0.0f,  //bottom left
		0.0f,  0.0f, 1.0f,  // colour
		-0.5f, 0.4f, 0.0f, // top right
		1.0f,  1.0f, 0.0f // colour

		
	};

	const std::vector<GLuint> indices{
		0, 1, 3,
		1, 2, 3
	};
        
	

	glGenVertexArrays(1,&VertexArray);
        glGenBuffers(1, &VertexBuffer);
	glGenBuffers(1,&ElementVertexBuffer);

	glBindVertexArray(VertexArray);

	glBindBuffer(GL_ARRAY_BUFFER,VertexBuffer);
	glBufferData(GL_ARRAY_BUFFER,vertexInfo.size() * sizeof(GL_FLOAT), vertexInfo.data(), GL_STATIC_DRAW);


	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ElementVertexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)0);
	glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(sizeof(GLfloat)* 3));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
	
}


void Shaders::OpenGLInfo(){

std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
std::cout << "Renderer: " << glGetString(GL_RENDERER);

}

