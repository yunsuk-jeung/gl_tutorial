#include "Viewer/Renderer/TriangleRendererWithTexture.h"
#include <iostream>


void TriangleRendererWithTexture::initialize(std::string shaderFolderPath) {

	shader.init(shaderFolderPath + "/triangle.vert", shaderFolderPath + "/triangle.frag");

	float vertexData[] = {
		-0.5f, -0.5f, // low left
		0.5f, -0.5f,  // lower-right
		0.0f, 0.5f,	 //  top - center corner
	};

	float texCoords[] = {
		0.0f, 0.0f, // low left
		1.0f, 0.0f, // lower-right
		0.5f,1.0f // top-center corner
	};

	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray);

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);




	shader.bind();
}


void TriangleRendererWithTexture::onDraw() {

	shader.bind();

	glBindVertexArray(vertexArray);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	shader.unbind();

}