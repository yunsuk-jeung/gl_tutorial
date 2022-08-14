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
	
	//triangleRenderer.initialize(shaderFolderPath);
	//rectengleRenderer.initialize(shaderFolderPath);
	//rectangleRendererWithTexture.initialize(shaderFolderPath);
	rttRenderer.initialize(shaderFolderPath);
	//cubeRenderer.initialize(shaderFolderPath);
}


void Viewer::onDraw() {
	glClearColor(0, 0, 0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	//triangleRenderer.onDraw(VPMatrix);
	//triangleRenderer.onDraw();
	//rectangleRendererWithTexture.onDraw();
	rttRenderer.onDraw();

	glutSwapBuffers();
	glutPostRedisplay();

	if (isExit == true)
	{
		glutLeaveMainLoop();
	}

}

void Viewer::onKeyPressed(unsigned char key, int x, int y) {
	switch (key)
	{
	case 27:
		isExit = true;
		break;
	default:
		break;
	}
}