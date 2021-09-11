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
		0,                  // 0번째 속성(attribute). 0 이 될 특별한 이유는 없지만, 쉐이더의 레이아웃(layout)와 반드시 맞추어야 합니다.
		3,                  // 크기(size)
		GL_FLOAT,           // 타입(type)
		GL_FALSE,           // 정규화(normalized)?
		0,                  // 다음 요소 까지 간격(stride)
		(void*)0            // 배열 버퍼의 오프셋(offset; 옮기는 값)
	);
	
	glDrawArrays(GL_TRIANGLES, 0, 6); // 버텍스 0에서 시작해서; 총 3개의 버텍스로 -> 하나의 삼각형
	glDisableVertexAttribArray(0);


}