const char* vertexShaderSource = R"(
#version 330 core
	layout(location = 0) in vec2 aPos;
	uniform mat4 model;

	void main()
	{
		gl_Position = model * vec4(aPos, 0.0, 1.0) ;
	}
)";

const char *fragmentShaderSource = R"(
	// Fragment shader
#version 330 core
	out vec4 FragColor;
	uniform vec3 color;
	void main() {
		FragColor = vec4(color.x, color.y, color.z, 1.0); // red
	}
)";

