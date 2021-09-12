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
	glDepthFunc(GL_ALWAYS);

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

	camPose.setIdentity();
	proj.setIdentity();

	//float dist = 10.0f;
	float dist = 10.0f;

	camPose.block<3, 1>(0, 3) = Eigen::Vector3f(0,0,dist);
	camPose = camPose.inverse();

	float dist2 = 1.0f/(dist + 1.0f);
	proj.block<3, 3>(0, 0) *= dist2;
	VPMatrix = proj * camPose;


	triangleRenderer.onDraw(VPMatrix);
	//cubeRenderer.onDraw();


	glutSwapBuffers();
	glutPostRedisplay();

}