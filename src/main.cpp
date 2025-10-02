#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>  // for glm::translate, rotate, scale, perspective
#include <glm/gtc/type_ptr.hpp>          // for glm::value_ptr

#include <shdrmangr.h>
#include <modelmgr.h>
#include <GameObject.h>
#include <objectmngr.h>

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
	register_shader_in_map(&defaultShaderProgram);

	mdlmgr = Modelmgr::get_instance();
	GameObject *go;
	GameObject *go2;

	go = 	create_game_object<GameObject>();
	go2 = create_game_object<GameObject>();
	go->model = &(mdlmgr->square_mesh);
	go->shader = &defaultShaderProgram;
	go->transform.color.z = 0.5;

	go2->model = &(mdlmgr->square2_mesh);
	go2->shader = &defaultShaderProgram;

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		update_game_objects();
		draw_game_objects();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}

