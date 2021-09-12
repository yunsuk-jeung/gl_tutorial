#include "Viewer/Renderer/TriangleRenderer.h"
#include <iostream>


void TriangleRenderer::initialize(std::string shaderFolderPath) {

	shader.init(shaderFolderPath + "/trianglevshader.txt", shaderFolderPath + "/trianglefshader.txt");

	vertexData.push_back(Eigen::Vector3f(-1.0f, -1.0f, 0.0f));
	vertexData.push_back(Eigen::Vector3f(1.0f, -1.0f, 0.0f));
	vertexData.push_back(Eigen::Vector3f(0.0f, 1.0f, 0.0f));

	MVPMatrix.setIdentity();

	MVPMatrix.block<3, 1>(0, 3) = Eigen::Vector3f(0, 0, 0);

	vertexHandle = glGetAttribLocation(shader.getShaderId(), "vertexModel");
	//vertexHandle = 0;
	glGenBuffers(1, &vertexBuffer);

	MVPMatrixHandle = glGetUniformLocation(shader.getShaderId(), "MVPMatrix");
	shader.bind();
	
}


void TriangleRenderer::onDraw(Eigen::Matrix4f VPMatrix) {

	shader.bind();

	MVPMatrix = VPMatrix;

	std::cout << ( MVPMatrix.block<3, 3>(0, 0) * vertexData[0] + MVPMatrix.block<3, 1>(0, 3) ).transpose() << std::endl;
	std::cout << ( MVPMatrix.block<3, 3>(0, 0) * vertexData[1] + MVPMatrix.block<3, 1>(0, 3) ).transpose() << std::endl;
	std::cout << ( MVPMatrix.block<3, 3>(0, 0) * vertexData[2] + MVPMatrix.block<3, 1>(0, 3) ).transpose() << std::endl;
	std::cout << std::endl;

	glUniformMatrix4fv(MVPMatrixHandle, 1, GL_FALSE, MVPMatrix.data());

	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertexData.size() * sizeof(float) * 3, &vertexData[0], GL_DYNAMIC_DRAW);
	glVertexAttribPointer(vertexHandle, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(vertexHandle);



	glDrawArrays(GL_TRIANGLES, 0, 6);

	shader.unbind();

}