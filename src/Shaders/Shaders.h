#pragma once
#include <iostream>
#include <glad/glad.h>
#include <string>

class Shaders{

public:


GLuint VertexArray = 0;
GLuint PipelineShader = 0;
GLuint VertexBuffer = 0;
GLuint ElementVertexBuffer = 0;




std::string LoadShader(const std::string& filename);
GLuint compileShader(GLuint type, const std::string &source);
GLuint CreateShader(const std::string& VertexShader, const std::string& FragmentShader);
void CreateGraphicsPipeline();
void VertexSpec();
void clearError();
bool checkError();
void OpenGLInfo();


// Making class to sort out these functions and will define them in their own cpp file. Still need to figure out why the core is being dumped.
	// Likely to an out of place pointer as it has something to do with memory access.

};
