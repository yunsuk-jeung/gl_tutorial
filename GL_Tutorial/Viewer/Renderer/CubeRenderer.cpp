#include "Viewer/Renderer/CubeRenderer.h"
#include <iostream>


void CubeRenderer::initialize(std::string shaderFolderPath) {
	
	shader.init(shaderFolderPath + "/trianglevshader.txt", shaderFolderPath + "/trianglefshader.txt");
	
	vertexHandle = glGetAttribLocation(shader.getShaderId(), "vertexModel");

	CubeRenderer::setData();
}

void CubeRenderer::setData() {

	vertexData.push_back(Eigen::Vector3f(-1.0f, -1.0f, 0.0f));
	vertexData.push_back(Eigen::Vector3f(1.0f, -1.0f, 0.0f));
	vertexData.push_back(Eigen::Vector3f(0.0f, 1.0f, 0.0f));
	//vertexData.push_back(Eigen::Vector3f(0.0f, 1.0f, 0.0f));
	//vertexData.push_back(Eigen::Vector3f(1.0f, -1.0f, 0.0f));
	//vertexData.push_back(Eigen::Vector3f(1.0f, 1.0f, 0.0f));

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertexData.size() * sizeof(float) * 3, &vertexData[0], GL_STATIC_DRAW);

}

void CubeRenderer::onDraw() {


	shader.bind();

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glVertexAttribPointer(
		0,                  // 0��° �Ӽ�(attribute). 0 �� �� Ư���� ������ ������, ���̴��� ���̾ƿ�(layout)�� �ݵ�� ���߾�� �մϴ�.
		3,                  // ũ��(size)
		GL_FLOAT,           // Ÿ��(type)
		GL_FALSE,           // ����ȭ(normalized)?
		0,                  // ���� ��� ���� ����(stride)
		(void*)0            // �迭 ������ ������(offset; �ű�� ��)
	);
	
	glDrawArrays(GL_TRIANGLES, 0, 6); // ���ؽ� 0���� �����ؼ�; �� 3���� ���ؽ��� -> �ϳ��� �ﰢ��
	glDisableVertexAttribArray(0);


}