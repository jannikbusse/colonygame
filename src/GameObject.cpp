#include<GameObject.h>
#include<iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


void test_function()
{
	std::cout << "Function workds \n";
	
}

void GameObject::go_test()
{
	std::cout << "Function workds from GO\n";
}


void GameObject::render()
{
	std::cout << "Rendering....\n";
	glDrawElements(GL_TRIANGLES, model->_vert_count, GL_UNSIGNED_INT, 0);

}

GameObject::GameObject()
{
	std::cout << "Running the init\n";
}
