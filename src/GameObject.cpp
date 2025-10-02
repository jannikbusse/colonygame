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

void GameObject::update(float deltaTime)
{
	std::cout << "updating game object \n";
	float newpos = (transform.get_position().x + 0.1 * deltaTime);
	if(newpos >= 1) newpos -= 2;
	transform.set_position_x(newpos);
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
