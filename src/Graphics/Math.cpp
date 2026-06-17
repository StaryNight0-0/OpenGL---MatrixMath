#include <iostream>
#include "Math.h"
#include <glm/vec3.hpp> 
#include <glm/vec4.hpp> 
#include <glm/mat4x4.hpp> 
#include <glm/ext/matrix_transform.hpp> 
#include <glm/ext/matrix_clip_space.hpp> 
#include <glm/ext/scalar_constants.hpp> 





// you would usually always normalize your vectors unless you are trying to calculate for for example
	//glm::vec3 A(3.0f,4.0f,0.0f);
	//glm::vec3 B(0.0f,7.0f,0.0f);
//	glm::vec3 C = glm::cross(A,B); // cross prodcut gives you a perpendicular vector to 2 other vectors. ORDER MATTERS
//	glm::mat4 mat(1.0f);

	//float f = glm::dot(glm::normalize(A),glm::normalize(B));  // Normalize puts the values between -1 and 1. For vectors it can signify a unit vector
        
//	std::cout << glm::length(A) << std::endl;
	//std::cout << glm::length(B) << std::endl;
//	std::cout << glm::dot(A,B) << std::endl;  // the dot function finds out how similar 2 vectors are so then we may be able to calculate the angle.
	// multiplies each component e.g. B.y x A.y = 28
	 
	
// w = 1 is a point, w = 0 is a direction(vector)

	//glm::vec4 vertex(1.0f,5.0f,1.0f,1.0f)
//	glm::mat4 model(1.0f);
	//Model * vertex
	// translate matrix example
	// model = glm::translate(glm::mat4(1.0f), glm::vec3(0.f,0.f,-2.0f));
	// Rotate matrix example
	// model = glm::rotate(glm::mat4(1.0f), glm::radians(180.0f), glm::vec3(0,1,0));
	// Scaling matrix example
	// model = glm::scale(glm::mat4(1.0f), glm::vec3(2.0f, 2.0f, 2.0f));


