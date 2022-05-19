#include <iostream>
#include <thread>

#include "Viewer/Viewer.h"

Viewer* viewer = nullptr;

void mainLoop() {

}



void onDraw() {

	viewer->onDraw();

}

void onKeyboard(unsigned char key, int x, int y) {
	viewer->onKeyPressed(key, x, y);

	switch (key) {
	case 'c':
		//cout << "copy map data" << endl;
		//copyMapData();
		break;
	default:
		break;
	}
}

int main(int argc, char** argv)
{
	viewer = new Viewer();
	viewer->initialize(argc, argv, "../../../../GL_Tutorial/Viewer/shader");

	std::thread mainThread(mainLoop);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);

	glutDisplayFunc(onDraw);
	glutKeyboardFunc(onKeyboard);

	glutMainLoop();

	if (mainThread.joinable()) {
		mainThread.join();
	}

	if (viewer) {
		delete viewer;
	}

	return 0;
}
