#include "Viewer/Viewer.h"
#include <iostream>


void Viewer::initialize(int argc, char** argv, std::string shaderFolderPath) {
	glutInit(&argc, argv);
	//glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("GL_TUTORIAL");
	glewInit();
	
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	shader.init(shaderFolderPath + "/trianglevshader.txt", shaderFolderPath + "/trianglefshader.txt");
	
	vertexHandle = glGetAttribLocation(shader.getShaderId(), "vertexModel");
}

void Viewer::setData() {

	vertexData.push_back(Eigen::Vector3f(-1.0f, -1.0f, 0.0f));
	vertexData.push_back(Eigen::Vector3f(1.0f, -1.0f, 0.0f));
	vertexData.push_back(Eigen::Vector3f(0.0f, 1.0f, 0.0f));
	vertexData.push_back(Eigen::Vector3f(0.0f, 1.0f, 0.0f));
	vertexData.push_back(Eigen::Vector3f(1.0f, -1.0f, 0.0f));
	vertexData.push_back(Eigen::Vector3f(1.0f, 1.0f, 0.0f));

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertexData.size() * sizeof(float) * 3, &vertexData[0], GL_STATIC_DRAW);

}

void Viewer::onDraw() {
	glClearColor(1, 0, 0, 1.0);
	//glViewport(0, 0, 600, 600);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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

	//shader.unbind();


	glutSwapBuffers();
	glutPostRedisplay();

}