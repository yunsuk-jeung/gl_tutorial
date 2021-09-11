#include <iostream>
#include <thread>

#include "Viewer/Viewer.h"

Viewer* viewer = nullptr;

void mainLoop() {

}



void onDraw() {

	viewer->onDraw();

}

int main(int argc, char** argv)
{
	viewer = new Viewer();
	viewer->initialize(argc, argv, "../../../../GL_Tutorial/Viewer/shader");
	viewer->setData();

	std::thread mainThread(mainLoop);

	glutDisplayFunc(onDraw);

	glutMainLoop();

	return 0;
}
