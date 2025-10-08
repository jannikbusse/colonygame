#include <renderer.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>  // for glm::translate, rotate, scale, perspective
#include <glm/gtc/type_ptr.hpp>          // for glm::value_ptr

#include <shdrmangr.h>
#include <iostream>
#include <clock.h>

std::chrono::duration<float> updateInterval = std::chrono::duration<float>(0);
std::chrono::time_point<std::chrono::high_resolution_clock> lastRenderDraw = std::chrono::high_resolution_clock::now();

float currRenderDraw = 0;

void set_max_render_frequency_hz(float hz)
{
	if(!hz) 
		updateInterval = std::chrono::duration<float>(0);
	else
	{
		updateInterval = std::chrono::duration<float>(1.0 / hz);
		std::cout << "Updated update interval";

	}
}


static void draw_game_object(GameObject *go)
{
	go->transform.update_model_matrix();
	glUniformMatrix4fv(go->shader->modelLoc, 1, GL_FALSE, glm::value_ptr(go->transform.model));
	glUniform3fv(go->shader->colorLoc, 1, glm::value_ptr(go->transform.color));

	(*go).render();
}

void draw_game_objects()
{
	if(updateInterval != std::chrono::duration<double>(0.0))
	{
		std::cout << "Frame update timer\n";
		if(lastRenderDraw + updateInterval <= lastTimeStamp )
		{
			lastRenderDraw = lastTimeStamp;
		}
		else {
			std::cout << "Render skipped\n";
			return;
		}
	}

	for(const auto& pair: shaderMap)
	{
		glUseProgram(pair.first->shaderProgram);
		for(GameObject *go : pair.second)
		{
			draw_game_object(go);
		}
	}
}


