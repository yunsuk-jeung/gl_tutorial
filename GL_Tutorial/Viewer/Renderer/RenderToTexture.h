#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>

#include <string>
#include <Eigen/Dense>
#include <vector>

#include "Viewer/shader/Shader.h"
#include "RectangleRendererWithTexture.h"

class RenderToTexture {
public:
	RenderToTexture() {
	}
	~RenderToTexture() {
	}

	void initialize(std::string shaderFolderPath);
	void onDraw();

	GLuint renderedTextureBuffer;
private:
	Shader shader;


	GLuint frameBufferId;
	GLuint renderedDepthBuffer;

	GLenum DrawBuffers;

	GLuint vertexArray;
	GLuint vertexBuffer;
	
	GLuint textureCoordsId;

	GLuint elementBuffer;


	RectangleRendererWithTexture rectangleRendererWithTexture;


};