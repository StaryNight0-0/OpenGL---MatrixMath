	#version 330 core

	layout(location = 0) in vec3 position;

        uniform mat4 u_View;
	uniform mat4 u_Perspective;
	uniform mat4 u_Model;



	void main()
	{
	  vec4 newPosition = u_Perspective * u_View * u_Model * vec4(position,1.0f);
	  gl_Position = newPosition;
	}
