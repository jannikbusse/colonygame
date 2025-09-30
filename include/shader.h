#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>  // for glm::translate, rotate, scale, perspective
#include <glm/gtc/type_ptr.hpp>          // for glm::value_ptr

class Shader
{
	public:
		unsigned int shaderProgram;
		GLuint modelLoc;
		GLuint colorLoc;

};

