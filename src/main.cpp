#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>  // for glm::translate, rotate, scale, perspective
#include <glm/gtc/type_ptr.hpp>          // for glm::value_ptr

#include <shdrmangr.h>
#include <modelmgr.h>
#include <GameObject.h>

#include <renderer.h>

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
	GameObject go;
	go.model = &(mdlmgr->square_mesh);
	go.shader = &defaultShaderProgram;
	go.transform.color.z = 0.5;
	go.transform.model =  glm::translate(go.transform.model, glm::vec3(0.5f, 0.0f, 0.0f));;

	GameObject go2;
	go2.model = &(mdlmgr->square_mesh);
	go2.shader = &defaultShaderProgram;
	go2.transform.model =  glm::translate(go2.transform.model, glm::vec3(-0.5f, 0.0f, 0.0f));;



	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glUseProgram(defaultShaderProgram.shaderProgram);


	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(mdlmgr->square_mesh._VAO);
		draw_game_object(go);
		draw_game_object(go2);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}

