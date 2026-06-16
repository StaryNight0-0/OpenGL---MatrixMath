#include <iostream>
#include "Math.h"
#include <glm/vec3.hpp> 
#include <glm/vec4.hpp> 
#include <glm/mat4x4.hpp> 
#include <glm/ext/matrix_transform.hpp> 
#include <glm/ext/matrix_clip_space.hpp> 
#include <glm/ext/scalar_constants.hpp> 



void math::vector(){

	glm::vec3 A(1.0f);
	glm::vec3 B(0.5f);

	float f = glm::dot(A,B);

	std::cout << "dot(A,B) is: " << f << std::endl;

}
