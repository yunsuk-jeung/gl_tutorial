#pragma once


#include <string>
#include <Eigen/Dense>
#include <vector>

#include "Viewer/Renderer/TriangleRenderer.h"
#include "Viewer/Renderer/CubeRenderer.h"


class Viewer {
public:
	Viewer() {
	}
	~Viewer() {
	}

	void initialize(int argc, char** argv, std::string shaderFolderPath);
	void onDraw();

private:
	
	Eigen::Matrix4f viewMatrix;
	
	Eigen::Matrix4f VPMatrix;


	TriangleRenderer triangleRenderer;
	CubeRenderer cubeRenderer;

};