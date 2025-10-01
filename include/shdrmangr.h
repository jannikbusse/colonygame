#ifndef _SHDRMNGR_H__
#define _SHDRMNGR_H__

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <vector>
#include <shader.h>



extern std::unordered_map<Shader*, std::vector<GameObject*>> shaderMap;

int shdrmngr_compile_shaders();
void register_shader_in_map(Shader *shader);
extern Shader defaultShaderProgram;



#endif
