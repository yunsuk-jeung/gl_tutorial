#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>

#include <string>
#include <Eigen/Dense>
#include <vector>

#include "Viewer/Renderer/RenderToTexture.h"
#include "Viewer/shader/Shader.h"


class RTTRenderer {
public:
	RTTRenderer() {
	}
	~RTTRenderer() {
	}

	void initialize(std::string shaderFolderPath);
	void onDraw();

private:
	Shader shader;
	
	RenderToTexture rtt;
	
	GLuint textureId;


	GLuint vertexArray;
	GLuint vertexBuffer;

	GLuint textureCoordsId;

	GLuint elementBuffer;

};