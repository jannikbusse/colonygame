#include <shdrmangr.h>
#include <iostream>

#include "../shader/shader.cpp"


Shader defaultShaderProgram;

static int link_shaders(unsigned int &shaderProgram, unsigned int vertexShaderHandle, unsigned int fragmentShaderHandle)
{
	char infoLog[512];
	int success;

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShaderHandle);   // your compiled vertex shader
	glAttachShader(shaderProgram, fragmentShaderHandle); // your compiled fragment shader
	glLinkProgram(shaderProgram);

	// Check linking errors
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if(!success)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER_PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		return 1;
	}
	return 0;
}

/*also links the shaders to the program*/
int shdrmngr_compile_shaders()
{

	unsigned int vertexShader;
	unsigned int fragmentShader;

	int res = 0;

	vertexShader = glCreateShader(GL_VERTEX_SHADER);   // create shader object
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL); // attach source
	glCompileShader(vertexShader);                     // compile shader

	// Check for errors
	int success;
	char infoLog[512];


	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::VERTEX_SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
		res = 1;
		goto cleanup_and_return;
	}

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	// Check for compilation errors
	success;
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::FRAGMENT_SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
		res = 1;
		goto cleanup_and_return;
	}

	if(link_shaders(defaultShaderProgram.shaderProgram, vertexShader, fragmentShader))
	{
		res = 1;
		goto cleanup_and_return;
	}
	defaultShaderProgram.modelLoc = glGetUniformLocation(defaultShaderProgram.shaderProgram, "model");
	defaultShaderProgram.colorLoc = glGetUniformLocation(defaultShaderProgram.shaderProgram, "color");

cleanup_and_return:
	// Once linked, you can delete the shader objects
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	//link shaders
	return res;
}

