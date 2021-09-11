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
	void setData();
	void onDraw();

private:

	Shader shader;
	GLuint vertexHandle;
	GLuint VertexArrayID;
	std::vector<Eigen::Vector3f> vertexData;

	GLuint vertexBuffer;

};