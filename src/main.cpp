#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

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

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glUseProgram(defaultShaderProgram);
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

