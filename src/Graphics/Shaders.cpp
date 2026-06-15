#include <iostream>
#include <glad/glad.h>
#include "Shaders.h"
#include <vector>
#include <string>
#include <fstream>


#define GLCheck(x) clearError(); x; checkError();

void Shaders::clearError(){

	while(glGetError() != GL_NO_ERROR){


	}
}

bool Shaders::checkError(){

 while(GLenum error = glGetError()){
		std::cout << "OpenGL Error" << error << std::endl;
		return true;  // Returns true if there is an error
	}
return false;
}

std::string Shaders::LoadShader(const std::string& filename){
	std::string result = "";
	std::string line = "";
	std::ifstream File(filename.c_str());
        std::cout << "Loading shader:" << filename << "\n";


	if(File.is_open()){
		std::cout << "file is open" << std::endl;    // THIS FUNCTION DOESNT WORK AT THE MOMENT SO SHADERS DONT LOAD NEEDS FIXING 
		while(std::getline(File, line)){             // NEED TO SORT OUT CMAKE SO THAT IT RECOGNISES THE STRING AS A FILE
			result += line + '\n';
		}
		File.close();
	}
	std::cout << result << std::endl;

return result;
}

GLuint Shaders::compileShader(GLuint type , const std::string &source){

GLuint shaderObject;

if(type == GL_VERTEX_SHADER){
       shaderObject = glCreateShader(GL_VERTEX_SHADER);
		std::cout << "Vertex shader found" << std::endl;
	}
else if(type == GL_FRAGMENT_SHADER){
       shaderObject = glCreateShader(GL_FRAGMENT_SHADER);
		std::cout << "Fragment Shader found" << std::endl;
	}

const char* src = source.c_str();	
glShaderSource(shaderObject, 1, &src, NULL);
glCompileShader(shaderObject);

//GLint shaderCompiled = GL_FALSE;
//lGetShaderiv(shaderObject, GL_COMPILE_STATUS, &shaderCompiled);

	//if(shaderCompiled != GL_TRUE){
	//	std::cout << "\nUnable to complile shader: \n" << shaderObject << std::endl; // check if the shader has been compiled
		//glDeleteShader(shaderObject);
	//	shaderObject = 0;
//	}
//	else{
		//std::cout << "Unable to open shader file: " << src << std::endl; // Checks if the file has been openend or not
//	}	

return shaderObject;
}


GLuint Shaders::CreateShader(const std::string &vertexShaderSource, const std::string &fragmentShaderSource){

GLuint Object = glCreateProgram();
GLuint myVertexShader = compileShader(GL_VERTEX_SHADER, vertexShaderSource);
GLuint myFragmentShader = compileShader(GL_FRAGMENT_SHADER,fragmentShaderSource);

glAttachShader(Object, myVertexShader);
	std::cout << "Vertex Shader Attached" << std::endl;
glAttachShader(Object, myFragmentShader);
	std::cout << "Fragment Shader Attached" << std::endl;
glLinkProgram(Object);
glValidateProgram(Object);
glDeleteShader(myVertexShader);
glDeleteShader(myFragmentShader);
	std::cout << "Shader successfully created :) " << std::endl;
return Object;
}

void Shaders::CreateGraphicsPipeline(){

std::string vertexShaderSource = LoadShader("Graphics/Vert.glsl");
std::string fragmentShaderSource = LoadShader("Graphics/Frag.glsl");

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

