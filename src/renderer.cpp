#include <renderer.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>  // for glm::translate, rotate, scale, perspective
#include <glm/gtc/type_ptr.hpp>          // for glm::value_ptr


#include <shdrmangr.h>
#include <iostream>


static void draw_game_object(GameObject *go)
{
	go->transform.update_model_matrix();
	glUniformMatrix4fv(go->shader->modelLoc, 1, GL_FALSE, glm::value_ptr(go->transform.model));
	glUniform3fv(go->shader->colorLoc, 1, glm::value_ptr(go->transform.color));

	(*go).render();
}

void draw_game_objects()
{

	for(const auto& pair: shaderMap)
	{

		glUseProgram(pair.first->shaderProgram);
		for(GameObject *go : pair.second)
		{
			draw_game_object(go);
		}
	}
}


