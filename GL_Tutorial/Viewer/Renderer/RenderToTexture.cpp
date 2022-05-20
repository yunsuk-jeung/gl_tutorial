#include "Viewer/Renderer/RenderToTexture.h"
#include <iostream>


void RenderToTexture::initialize(std::string shaderFolderPath) {

	glGenFramebuffers(1, &frameBufferId);
	glBindFramebuffer(GL_FRAMEBUFFER, frameBufferId);

	glGenTextures(1, &renderedTextureBuffer);
	glBindTexture(GL_TEXTURE_2D, renderedTextureBuffer);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 600, 600, 0, GL_RGB, GL_UNSIGNED_BYTE, 0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glGenRenderbuffers(1, &renderedDepthBuffer);
	glBindRenderbuffer(GL_RENDERBUFFER, renderedDepthBuffer);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, 600, 600);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, renderedDepthBuffer);
	glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, renderedTextureBuffer, 0);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, renderedTextureBuffer, 0);

	//DrawBuffers = GL_COLOR_ATTACHMENT0;
	//glDrawBuffers(1, &DrawBuffers);

	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	rectangleRendererWithTexture.initialize(shaderFolderPath);
}


void RenderToTexture::onDraw() {

	glBindFramebuffer(GL_FRAMEBUFFER, frameBufferId);

	glViewport(0, 0, 600, 600);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_ALWAYS);


	rectangleRendererWithTexture.onDraw();

	glBindFramebuffer(GL_FRAMEBUFFER, 0);

}