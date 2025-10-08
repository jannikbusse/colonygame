#include <objectmngr.h>
#include <iostream>
#include <clock.h>


std::vector<GameObject*> gameObjects;





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
	for(GameObject *go: gameObjects)
	{
		go->update(deltaTime);
	}
}
