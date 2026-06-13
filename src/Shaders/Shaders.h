#pragma once
#include <iostream>
#include <glad/glad.h>

class Shaders{

public:

GLuint gVertexArray = 0;
GLuint gPipelineShader = 0;
GLuint gVertexBuffer = 0;
GLuint gElementVertexBuffer = 0;


const std::string gVertexShaderSource = 
	"#version 330 core\n"
	"layout(location = 0) in vec3 position;\n"
	"void main()\n"
	"{\n"
	"   gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
	"}\n";
                                                                                       //Some hardcoded shaders to test OpenGL

const std::string gFragmentShaderSource = 
	"#version 410 core\n"
	"out vec4 color;\n"
	"void main()\n"
	"{\n"
	"  color = vec4(1.0f, 0.5f, 0.0f, 1.0f);\n"
	"}\n";


GLuint compileShader(GLuint type, const std::string &source);
GLuint CreateShader(const std::string& VertexShader, const std::string& FragmentShader);
void CreateGraphicsPipeline();
void VertexSpec();
void OpenGLInfo();

// Making class to sort out these functions and will define them in their own cpp file. Still need to figure out why the core is being dumped.
	// Likely to an out of place pointer as it has something to do with memory access.

};
