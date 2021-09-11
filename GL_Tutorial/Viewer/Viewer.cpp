#include "Viewer/Viewer.h"
#include <iostream>


void Viewer::initialize(int argc, char** argv, std::string shaderFolderPath) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("GL_TUTORIAL");
	glewInit();
	
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	
	triangleRenderer.initialize(shaderFolderPath);
	cubeRenderer.initialize(shaderFolderPath);
}


void Viewer::onDraw() {
	glClearColor(0, 0, 0, 1.0);
	//glViewport(0, 0, 600, 600);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//triangleRenderer.onDraw();
	cubeRenderer.onDraw();


	glutSwapBuffers();
	glutPostRedisplay();

}