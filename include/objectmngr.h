#pragma once

#include <GameObject.h>
#include <vector>
#include <shdrmangr.h>

#include <chrono>

extern std::vector<GameObject*> gameObjects;


void register_game_object(GameObject *go);


void update_game_objects();

template <typename T, typename... Args>
GameObject* create_game_object(Args&&... args) {
    static_assert(std::is_base_of<GameObject, T>::value, "T must derive from GameObject");
    T *res = new T(std::forward<Args>(args)...);

	 register_game_object(res);
	 return res;
}
