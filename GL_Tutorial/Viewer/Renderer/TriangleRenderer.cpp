#include "Viewer/Renderer/TriangleRenderer.h"
#include <iostream>


void TriangleRenderer::initialize(std::string shaderFolderPath) {

	shader.init(shaderFolderPath + "/triangle.vert", shaderFolderPath + "/triangle.frag");

	vertexData.push_back(Eigen::Vector3f(0.5f, 0.5f, 0.0f));
	vertexData.push_back(Eigen::Vector3f(0.5f, -0.5f, 0.0f));
	vertexData.push_back(Eigen::Vector3f(-0.5f, 0.5f, 0.0f));



	MVPMatrix.setIdentity();

	MVPMatrix.block<3, 1>(0, 3) = Eigen::Vector3f(0, 0, 0);

	//vertexHandle = glGetAttribLocation(shader.getShaderId(), "vertexModel");

	//MVPMatrixHandle = glGetUniformLocation(shader.getShaderId(), "MVPMatrix");

	
	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray);

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertexData.size() * sizeof(float) * 3, &vertexData[0], GL_DYNAMIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);



	
	shader.bind();
}


void TriangleRenderer::onDraw() {

	shader.bind();

	glBindVertexArray(vertexArray);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	shader.unbind();

}