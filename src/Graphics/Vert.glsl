	#version 410 core

	layout(location = 0) in vec3 position;
	layout(location = 1) in vec3 aColour;

        uniform mat4 u_ModelMatrix;

	out vec3 Colour;


	void main()
	{
	  vec4 newPosition = u_ModelMatrix * vec4(position,1.0f);
	  gl_Position = vec4(newPosition.x,newPosition.y,newPosition.z, 1.0f);
	  Colour = aColour;
	}
