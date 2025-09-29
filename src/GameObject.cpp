#include<GameObject.h>
#include<iostream>

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
}

GameObject::GameObject()
{
	std::cout << "Running the init\n";
	shader = -1;
}
