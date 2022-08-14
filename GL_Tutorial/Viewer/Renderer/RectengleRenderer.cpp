#include "Viewer/Renderer/RectengleRenderer.h"
#include <iostream>


void RectengleRenderer::initialize(std::string shaderFolderPath) {

	shader.init(shaderFolderPath + "/triangle.vert", shaderFolderPath + "/triangle.frag");

	vertexData.push_back(Eigen::Vector3f(0.5f, 0.5f, 0.0f)); // top right
	vertexData.push_back(Eigen::Vector3f(0.5f, -0.5f, 0.0f)); // bottom right
	vertexData.push_back(Eigen::Vector3f(-0.5f, -0.5f, 0.0f)); // bottom left
	vertexData.push_back(Eigen::Vector3f(-0.5f, 0.5f, 0.0f)); // top left

	// upper triangle
	indices.push_back(0);	indices.push_back(1);	indices.push_back(3);
	// lower triangle
	indices.push_back(1);	indices.push_back(2);	indices.push_back(3);


	MVPMatrix.setIdentity();
	MVPMatrix.block<3, 1>(0, 3) = Eigen::Vector3f(0, 0, 0);

	//vertexHandle = glGetAttribLocation(shader.getShaderId(), "vertexModel");

	//MVPMatrixHandle = glGetUniformLocation(shader.getShaderId(), "MVPMatrix");s

	//glGenVertexArrays(1, &vertexArray);
	//glBindVertexArray(vertexArray);


	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertexData.size() * sizeof(float) * 3, &vertexData[0], GL_DYNAMIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), &indices[0], GL_STATIC_DRAW);




	shader.bind();
}


void RectengleRenderer::onDraw() {

	shader.bind();

	//glBindVertexArray(vertexArray);

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	//glBufferData(GL_ARRAY_BUFFER, vertexData.size() * sizeof(float) * 3, &vertexData[0], GL_DYNAMIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);


	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	shader.unbind();

}