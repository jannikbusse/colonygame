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
	private:
		bool dirtyMatrix;
		glm::vec3 position = glm::vec3(0.0f);
		glm::vec3 rotation = glm::vec3(0.0f); // Euler angles in radians (pitch, yaw, roll)
		glm::vec3 scale    = glm::vec3(1.0f);

	public:
		glm::mat4 model;
		glm::vec3 color;
	
		void update_model_matrix();

		void set_position(float x, float y, float z)
		{
			position.x = x;
			position.y = y;
			position.z = z;
			dirtyMatrix = 1;
		}

		void set_position_x(float x)
		{
			position.x = x;
			dirtyMatrix = 1;
		}

		void set_position_y(float y)
		{
			position.y = y;
			dirtyMatrix = 1;
		}

		void set_position_z(float z)
		{
			position.z = z;
			dirtyMatrix = 1;
		}

		glm::vec3 get_position()
		{
			return position;
		}

		glm::vec3 *get_position_ptr()
		{
			return &position;
		}

		void translate(float x, float y, float z)
		{
			position.x += x;
			position.y += y;
			position.z += z;
			dirtyMatrix = 1;
		}

		void translate(const glm::vec3& offset)
		{
			 position += offset;
			 dirtyMatrix = true;
		}


		glm::mat4 get_model_matrix() const {
			  glm::mat4 model = glm::mat4(1.0f);
			  
			  model = glm::translate(model, position);
			  model = glm::rotate(model, rotation.z, glm::vec3(0, 0, 1));
			  model = glm::rotate(model, rotation.y, glm::vec3(0, 1, 0));
			  model = glm::rotate(model, rotation.x, glm::vec3(1, 0, 0));

			  model = glm::scale(model, scale);

			  return model;
		 }


		Transform()
		{
			model = glm::mat4(1.0f);
			color.x = 1;
			color.y = 0;
			color.z = 0;

			model = get_model_matrix();
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
		void update(float deltaTime);

};

void test_function();

#endif
