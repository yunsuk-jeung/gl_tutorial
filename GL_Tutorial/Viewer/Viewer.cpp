#include "Viewer/Viewer.h"
#include "Viewer/GLMatrix.hpp"
#include <iostream>


void Viewer::initialize(int argc, char** argv, std::string shaderFolderPath) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("GL_TUTORIAL");
	glewInit();
	
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_ALWAYS);

	orthoSize[0] = initOrthoSize;
	orthoSize[1] = initOrthoSize;
	orthoShift.setZero();


	viewMatrix.setIdentity();
	
	triangleRenderer.initialize(shaderFolderPath);
	cubeRenderer.initialize(shaderFolderPath);
}


void Viewer::onDraw() {
	glClearColor(0, 0, 0, 1.0);
	//glViewport(0, 0, 600, 600);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	Eigen::Matrix4f camPose;
	Eigen::Matrix4f proj;
	Eigen::Matrix4f view;

	proj.setIdentity();
	std::cout << orthoShift.transpose() << std::endl;

	float dist = 1.0f;
	orthoSize.setOnes();
	orthoSize *= dist;

	std::cout << orthoSize.transpose() << std::endl;

	proj = GLMatrix::ortho(
		-orthoSize[0] + orthoShift.y(), orthoSize[0] + orthoShift.y(),
		-orthoSize[1] - orthoShift.x(), orthoSize[1] - orthoShift.x(),
		0.1f, 1000.f);

	float dist2 = 50.0f;

	view = GLMatrix::lookAt(Eigen::Vector3f(0.0f, 0.0f, dist2), Eigen::Vector3f(0.0f, 0.0f, 0.0f), Eigen::Vector3f(0.0f, 1.0f, 0.0f));

	VPMatrix = proj * view;

	std::cout << VPMatrix << std::endl;


	triangleRenderer.onDraw(VPMatrix);
	//cubeRenderer.onDraw();


	glutSwapBuffers();
	glutPostRedisplay();

}