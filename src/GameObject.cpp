#include<GameObject.h>
#include<iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <linux/limits.h>


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
	glBindVertexArray(model->_VAO);
	glDrawElements(GL_TRIANGLES, model->_vert_count, GL_UNSIGNED_INT, 0);

}

GameObject::GameObject()
{
	std::cout << "Running the init\n";
}

void Transform::update_model_matrix()
{
	if (dirtyMatrix)
	{
		dirtyMatrix = 0;
		model = get_model_matrix();
	}
}
