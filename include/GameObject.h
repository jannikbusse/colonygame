#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

#include <modelmgr.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>  // for glm::translate, rotate, scale, perspective
#include <glm/gtc/type_ptr.hpp>          // for glm::value_ptr
													  //
#include <shader.h>

struct Transform
{
	glm::mat4 model;
	glm::vec3 color;

	Transform()
	{
		model = glm::mat4(1.0f);
		color.x = 1;
		color.y = 0;
		color.z = 0;
	}
};

class GameObject
{
	private:


	public:
		GameObject();
		struct Transform transform;
		struct model_info *model;
		Shader *shader;
		void go_test();
		void render();

};

void test_function();

#endif
