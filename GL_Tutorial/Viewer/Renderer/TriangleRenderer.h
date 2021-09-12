#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>

#include <string>
#include <Eigen/Dense>
#include <vector>

#include "Viewer/shader/Shader.h"

class TriangleRenderer {
public:
	TriangleRenderer() {
	}
	~TriangleRenderer() {
	}

	void initialize(std::string shaderFolderPath);
	void onDraw(Eigen::Matrix4f VPMatrix);

private:
	Shader shader;
	
	GLuint MVPMatrixHandle;
	Eigen::Matrix4f MVPMatrix;

	GLuint vertexHandle;
	GLuint vertexBuffer;
	std::vector<Eigen::Vector3f> vertexData;


};