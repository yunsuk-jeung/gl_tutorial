#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>

#include <string>
#include <Eigen/Dense>
#include <vector>

#include "Viewer/shader/Shader.h"

class RectangleRendererWithTexture {
public:
	RectangleRendererWithTexture() {
	}
	~RectangleRendererWithTexture() {
	}

	void initialize(std::string shaderFolderPath);
	void onDraw();

private:
	Shader shader;
	
	GLuint MVPMatrixHandle;
	Eigen::Matrix4f MVPMatrix;

	GLuint vertexHandle;
	
	GLuint textureId;
	GLuint textureId2;
	GLuint textureCoordsId;
	GLuint vertexArray;
	GLuint vertexBuffer;
	GLuint elementBuffer;
	//float vertexData[9];


};