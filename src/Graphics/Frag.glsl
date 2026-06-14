	#version 410 core

	in vec3 ourColour;
	out vec4 outColour;
	void main()
	{
	  outColour = vec4(ourColour, 1.0);

	}


