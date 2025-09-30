#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>  // for glm::translate, rotate, scale, perspective
#include <glm/gtc/type_ptr.hpp>          // for glm::value_ptr

#include <shdrmangr.h>
#include <modelmgr.h>
#include <GameObject.h>

Modelmgr *mdlmgr;

void framebuffer_size_callback(GLFWwindow* w,int width,int height){
	glViewport(0,0,width,height);
}

int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Window", nullptr, nullptr);
	if (!window) { glfwTerminate(); return -1; }
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Failed to init GLAD\n";
		return -1;
	}

	if(shdrmngr_compile_shaders()) 
	{
		std::cout << "Failed to compile shaders" << std::endl;
		return -1;
	}

	mdlmgr = Modelmgr::get_instance();

	test_function();
	GameObject go;
	go.go_test();

	glm::mat4 model = glm::mat4(1.0f); // identity matrix
	model = glm::translate(model, glm::vec3(-1, 1, 1));   // position
																			// model = glm::rotate(model, angle, glm::vec3(0.0f, 1.0f, 0.0f)); // rotation
																			// model = glm::scale(model, glm::vec3(sx, sy, sz));    // scale
	glm::vec3 color(1.0f, 2.0f, 0.0f);


	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glUseProgram(defaultShaderProgram);

	GLuint modelLoc = glGetUniformLocation(defaultShaderProgram, "model");
	GLuint colorLoc = glGetUniformLocation(defaultShaderProgram, "color");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	glUniform3fv(colorLoc, 1, glm::value_ptr(color));

	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(mdlmgr->square_mesh._VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}

