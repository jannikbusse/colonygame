#ifndef _RENDERER_H__
#define _RENDERER_H__

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>  // for glm::translate, rotate, scale, perspective
#include <glm/gtc/type_ptr.hpp>          // for glm::value_ptr
#include <GameObject.h>

void draw_game_objects(GLFWwindow* &window);
void set_max_render_frequency_hz(float hz);

#endif
