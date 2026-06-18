	#version 410 core

	layout(location = 0) in vec3 position;
	layout(location = 1) in vec3 aColour;

        uniform mat4 u_ModelMatrix;
	uniform mat4 u_Perspective;

	out vec3 Colour;


	void main()
	{
	  vec4 newPosition = u_Perspective * u_ModelMatrix * vec4(position,1.0f);
	  gl_Position = newPosition;
	  Colour = aColour;
	}
