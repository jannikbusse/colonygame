#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <modelmgr.h>
#include <Shapes.h>
#include <iostream>


void init_model_info(model_info *model, unsigned int VAO, unsigned int nIndices)
{
	model->_VAO = VAO;
	model->_vert_count = nIndices;
}

float square_vertices[] = {
    // positions (x, y)
    -0.5f, -0.5f, // bottom-left
     0.5f, -0.5f, // bottom-right
     0.5f,  0.5f, // top-right
    -0.5f,  0.5f  // top-left
};


float square2_vertices[] = {
    // positions (x, y)
    -0.5f, -0.5f, // bottom-left
     0.5f, -0.5f, // bottom-right
     0.5f,  0.5f, // top-right
    -0.5f,  0  // top-left
};

unsigned int square_indices[] = {
    0, 1, 2, // first triangle
    2, 3, 0  // second triangle
};



unsigned int create_vao(float *verts,unsigned int *indices, unsigned int nVerts, unsigned int nIdx)
{
	unsigned int VAO, VBO, EBO;

	// Generate IDs
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	// 1. Bind and fill VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * nVerts, verts, GL_STATIC_DRAW);

	// 2. Bind and fill EBO (element/index buffer)
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(float) * nIdx, indices, GL_STATIC_DRAW);

	// 3. Define vertex attribute layout
	glVertexAttribPointer(
			0,          // attribute 0 (matches layout(location = 0) in shader)
			2,          // number of components (x, y)
			GL_FLOAT,   // type
			GL_FALSE,   // normalized?
			2 * sizeof(float), // stride (space between consecutive vertices)
			(void*)0    // offset in buffer
			);
	glEnableVertexAttribArray(0);

	// 4. Unbind VAO (optional)
	glBindVertexArray(0);

    // You can delete the VBO/EBO here if you want, VAO keeps references
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
	return VAO;
}


unsigned int create_square_vao()
{
	unsigned int VAO, VBO, EBO;

	// Generate IDs
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	// 1. Bind and fill VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(square_vertices), square_vertices, GL_STATIC_DRAW);

	// 2. Bind and fill EBO (element/index buffer)
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(square_indices), square_indices, GL_STATIC_DRAW);

	// 3. Define vertex attribute layout
	glVertexAttribPointer(
			0,          // attribute 0 (matches layout(location = 0) in shader)
			2,          // number of components (x, y)
			GL_FLOAT,   // type
			GL_FALSE,   // normalized?
			2 * sizeof(float), // stride (space between consecutive vertices)
			(void*)0    // offset in buffer
			);
	glEnableVertexAttribArray(0);

	// 4. Unbind VAO (optional)
	glBindVertexArray(0);

    // You can delete the VBO/EBO here if you want, VAO keeps references
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
	return VAO;
}

Modelmgr* Modelmgr::instance_ = nullptr;
Modelmgr* Modelmgr::get_instance()
{
	if(instance_ == nullptr)
	{
		instance_ = new Modelmgr();
		std::cout << "Created the singleton instance\n";
	}
	return instance_;
}

Modelmgr::Modelmgr()
{
	std::cout << "Running Modelmgr constructor\n";
	// init_model_info(&square_mesh, create_vao(square_vertices, square_indices), 6);
	init_model_info(&square2_mesh, create_vao(square2_vertices, square_indices, 8, 6), 6);
	init_model_info(&square_mesh, create_vao(square_vertices, square_indices, 8, 6), 6);
}

