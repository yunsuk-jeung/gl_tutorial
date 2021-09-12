#include "Viewer/Renderer/CubeRenderer.h"
#include <iostream>


void CubeRenderer::initialize(std::string shaderFolderPath) {

	shader.init(shaderFolderPath + "/trianglevshader.txt", shaderFolderPath + "/trianglefshader.txt");

	vertexHandle = glGetAttribLocation(shader.getShaderId(), "vertexModel");

	vertexData.push_back(Eigen::Vector3f(-1.0f, -1.0f, 0.0f));
	vertexData.push_back(Eigen::Vector3f(1.0f, -1.0f, 0.0f));
	vertexData.push_back(Eigen::Vector3f(0.0f, 1.0f, 0.0f));
	//vertexData.push_back(Eigen::Vector3f(0.0f, 1.0f, 0.0f));
	//vertexData.push_back(Eigen::Vector3f(1.0f, -1.0f, 0.0f));
	//vertexData.push_back(Eigen::Vector3f(1.0f, 1.0f, 0.0f));

	vertexHandle = glGetAttribLocation(shader.getShaderId(), "vertexModel");
	//vertexHandle = 0;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertexData.size() * sizeof(float) * 3, &vertexData[0], GL_STATIC_DRAW);

}


void CubeRenderer::onDraw() {


	shader.bind();

	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glVertexAttribPointer(vertexHandle, 3, GL_FLOAT, GL_FALSE,0,(void*)0);
	glEnableVertexAttribArray(vertexHandle);

	glDrawArrays(GL_TRIANGLES, 0, 6); // ���ؽ� 0���� �����ؼ�; �� 3���� ���ؽ��� -> �ϳ��� �ﰢ��
	//glDisableVertexAttribArray(0);

	shader.unbind();

}