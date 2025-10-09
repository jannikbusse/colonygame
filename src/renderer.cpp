#include <renderer.h>

#include <shdrmangr.h>
#include <iostream>
#include <clock.h>


std::chrono::milliseconds updateInterval = std::chrono::milliseconds(static_cast<int>(0));
std::chrono::time_point<std::chrono::high_resolution_clock> lastRenderDraw = std::chrono::high_resolution_clock::now();


void set_max_render_frequency_hz(float hz)
{
	if(!hz) 
		updateInterval = std::chrono::milliseconds(static_cast<int>(0));
	else
	{
		updateInterval = std::chrono::milliseconds(static_cast<int>(1000.0f / hz));
	}
}


static void draw_game_object(GameObject *go)
{
	go->transform.update_model_matrix();
	glUniformMatrix4fv(go->shader->modelLoc, 1, GL_FALSE, glm::value_ptr(go->transform.model));
	glUniform3fv(go->shader->colorLoc, 1, glm::value_ptr(go->transform.color));

	go->render();
}

void draw_game_objects(GLFWwindow* &window)
{

	auto now = std::chrono::high_resolution_clock::now();
	std::cout << "[DEBUG] Time since last render: "
		<< std::chrono::duration_cast<std::chrono::milliseconds>(now - lastRenderDraw).count()
		<< " ms (interval: " << updateInterval.count() * 1000 << " ms)\n";


	std::cout << "[DEBUG] difference: "
		<< std::chrono::duration_cast<std::chrono::milliseconds>(lastTimeStamp - lastRenderDraw).count()
		<< " ms (interval: " << updateInterval.count() * 1000 << " ms)\n";

	std::cout << "Updated update interval " << updateInterval.count() << "\n";
	if(updateInterval != std::chrono::duration<float>(0.0))
	{
		if(lastRenderDraw + updateInterval <= lastTimeStamp )
		{
			std::cout << "Render not skipped!!!\n";
			lastRenderDraw = lastTimeStamp;
		}
		else {
			std::cout << "  Render skipped\n";
			return;
		}
	}

	glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
	// Clear the depth buffer each frame along with the color buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for(const auto& pair: shaderMap)
	{
		glUseProgram(pair.first->shaderProgram);
		for(GameObject *go : pair.second)
		{
			draw_game_object(go);
		}
	}


	glfwSwapBuffers(window);
	glfwPollEvents();
}


