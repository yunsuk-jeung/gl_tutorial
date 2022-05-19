#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>

#include <string>
#include <Eigen/Dense>
#include <vector>

#include "Viewer/shader/Shader.h"

class TriangleRendererWithTexture {
public:
	TriangleRendererWithTexture() {
	}
	~TriangleRendererWithTexture() {
	}

	void initialize(std::string shaderFolderPath);
	void onDraw();

private:
	Shader shader;
	
	GLuint MVPMatrixHandle;
	Eigen::Matrix4f MVPMatrix;

	GLuint vertexHandle;
	
	GLuint vertexArray;
	GLuint vertexBuffer;

	//float vertexData[9];


};