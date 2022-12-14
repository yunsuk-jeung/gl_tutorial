#include "Viewer/Renderer/RectangleRendererWithTexture.h"
#include <iostream>
#include <opencv2/opencv.hpp>


void RectangleRendererWithTexture::initialize(std::string shaderFolderPath) {

	shader.init(shaderFolderPath + "/triangleWithTexture.vert", shaderFolderPath + "/triangleWithTexture.frag");
	std::cout << "RectangleRendererWithTexture shader ID : " << shader.getShaderId() << "texture1 : " << glGetUniformLocation(shader.getShaderId(), "texture1") << std::endl;

	float vertexData[] = {
		-0.5f, 0.5f, 0.0f,// top left
		0.5f, 0.5f, 0.0f, // top right
		0.5f, -0.5f, 0.0f, // bottom-right
		-0.5f, -0.5f, 0.0f, // bottom-left
	};

	unsigned int indices[] = { 0,1,2,0,2,3 };

	float texCoords[] = {
		0.f, 1.0f, // top left
		1.f,1.0f, // top right
		1.0f, 0.0f, // bottom right
		0.0f, 0.0f, // bottom left
	};

	cv::Mat image = cv::imread("../../../../image.jpg", cv::IMREAD_COLOR);
	cv::flip(image, image, 0);
	cv::cvtColor(image, image, CV_BGR2RGB);
	int width = image.cols;
	int height = image.rows;
	int length = image.cols * image.rows * image.channels();
	unsigned char* data = image.data;

	cv::Mat image2 = cv::imread("../../../../image2.png", cv::IMREAD_COLOR);
	cv::flip(image2, image2, 0);
	cv::cvtColor(image2, image2, CV_BGR2RGB);
	int width2 = image2.cols;
	int height2 = image2.rows;
	int length2 = image2.cols * image2.rows * image2.channels();
	unsigned char* data2 = image2.data;

	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	glGenTextures(1, &textureId2);
	glBindTexture(GL_TEXTURE_2D, textureId2);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width2, height2, 0, GL_RGB, GL_UNSIGNED_BYTE, data2);
	glGenerateMipmap(GL_TEXTURE_2D);
	   
	glBindTexture(GL_TEXTURE_2D, 0);


	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray);

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_DYNAMIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glGenBuffers(1, &textureCoordsId);
	glBindBuffer(GL_ARRAY_BUFFER, textureCoordsId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(texCoords), texCoords, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);

	glGenBuffers(1, &elementBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glBindVertexArray(0);

	shader.bind();
}


void RectangleRendererWithTexture::onDraw() {

	shader.bind();

	glUniform1i(glGetUniformLocation(shader.getShaderId(), "texture1"), 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureId);

	glUniform1i(glGetUniformLocation(shader.getShaderId(), "texture2"), 1);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, textureId2);


	glBindVertexArray(vertexArray);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	shader.unbind();

}