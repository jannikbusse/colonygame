#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

#include <modelmgr.h>

class GameObject
{
	private:


	public:
		GameObject();
		struct model_info model;
		int shader;
		void go_test();
		void render();

};

void test_function();

#endif
