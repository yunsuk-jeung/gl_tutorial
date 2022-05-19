#pragma once


#include <string>
#include <Eigen/Dense>
#include <vector>

#include "Viewer/Renderer/CubeRenderer.h"
#include "Viewer/Renderer/RectengleRenderer.h"
#include "Viewer/Renderer/RectangleRendererWithTexture.h"

#include "Viewer/Renderer/TriangleRenderer.h"


class Viewer {
public:
	Viewer() {
	}
	~Viewer() {
	}

	void initialize(int argc, char** argv, std::string shaderFolderPath);
	void onDraw();

	void onKeyPressed(unsigned char key, int x, int y);


private:
	
	bool isExit = false;

	float initOrthoSize = 10.0f;
	Eigen::Vector2f orthoSize;
	Eigen::Vector2f orthoShift;

	Eigen::Matrix4f viewMatrix;
	Eigen::Matrix4f VPMatrix;


	TriangleRenderer triangleRenderer;
	CubeRenderer cubeRenderer;
	RectengleRenderer rectengleRenderer;
	RectangleRendererWithTexture rectangleRendererWithTexture;

};