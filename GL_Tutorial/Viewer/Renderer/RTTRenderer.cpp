#include "Viewer/Renderer/RTTRenderer.h"
#include <iostream>
#include <opencv2/opencv.hpp>


void RTTRenderer::initialize(std::string shaderFolderPath) {

	shader.init(shaderFolderPath + "/triangleWithTexture.vert", shaderFolderPath + "/triangleWithTexture.frag");
	std::cout << "RTTRenderer shader ID : " << shader.getShaderId() << "texture1 : " << glGetUniformLocation(shader.getShaderId(),"texture1") << std::endl;

	rtt.initialize(shaderFolderPath);
	float vertexData[] = {
	-0.5f, 0.5f, 0.0f,// top left
	0.5f, 0.5f, 0.0f, // top right
	0.5f, -0.5f, 0.0f, // bottom-right
	-0.5f, -0.5f, 0.0f, // bottom-left
	};

	unsigned int indices[] = { 0,1,2,0,2,3 };

	float texCoords[] = {
		0.f, 1.0f, // top left
		1.f,1.0f, // top right
		1.0f, 0.0f, // bottom right
		0.0f, 0.0f, // bottom left
	};
	
	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray);

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_DYNAMIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glGenBuffers(1, &textureCoordsId);
	glBindBuffer(GL_ARRAY_BUFFER, textureCoordsId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(texCoords), texCoords, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);

	glGenBuffers(1, &elementBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glBindVertexArray(0);
}


void RTTRenderer::onDraw() {

	rtt.onDraw();

	shader.bind();

	glUniform1i(glGetUniformLocation(shader.getShaderId(), "texture1"), 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, rtt.renderedTextureBuffer);

	//glBindTexture(GL_TEXTURE_2D, rtt.renderedTextureBuffer);

	glBindVertexArray(vertexArray);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT,0);

	shader.unbind();

}