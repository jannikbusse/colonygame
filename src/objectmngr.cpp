#include <objectmngr.h>
#include <iostream>


std::vector<GameObject*> gameObjects;

float deltaTime;
std::chrono::time_point<std::chrono::high_resolution_clock> lastTimeStamp = std::chrono::high_resolution_clock::now() ;


inline void update_delta_time()
{
	std::chrono::time_point<std::chrono::high_resolution_clock> currentTimeStamp = std::chrono::high_resolution_clock::now();
  	std::chrono::duration<float> delta = currentTimeStamp - lastTimeStamp;
   deltaTime = delta.count(); 
	lastTimeStamp = currentTimeStamp;
}


void register_game_object(GameObject *go)
{
	if(!go) return;
	gameObjects.push_back(go);
	if(!go->shader)
		go->shader = &defaultShaderProgram;
	shaderMap[go->shader].push_back(go);
}


void update_game_objects()
{

	update_delta_time();
	std::cout << "DELTA TIME " << deltaTime << std::endl;
	for(GameObject *go: gameObjects)
	{
		go->update(deltaTime);
	}
}
