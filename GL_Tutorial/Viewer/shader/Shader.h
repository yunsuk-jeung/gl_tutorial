#pragma once

#include <iostream>
#include<fstream>
#include <string>

#include "GL/glew.h"
#include "GL/freeglut.h"

class Shader {
public:
	Shader() {

	}
	~Shader() {
		glDetachShader(shaderId, vertexShader);
		glDetachShader(shaderId, fragmentShader);

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
		glDeleteProgram(shaderId);
	}

	void init(std::string vshaderpath, std::string fshaderpath) {
		vertexShader = loadShader(GL_VERTEX_SHADER, vshaderpath);
		fragmentShader = loadShader(GL_FRAGMENT_SHADER, fshaderpath);

		shaderId = glCreateProgram();
		glAttachShader(shaderId, vertexShader);
		glAttachShader(shaderId, fragmentShader);
		glLinkProgram(shaderId);

	};

	int loadShader(GLenum type, std::string filename) {
		GLuint shader;
		GLint compiled;
		shader = glCreateShader(type);

		if(shader == 0) {
			std::cout << "shader create error" << std::endl;
			return 0;
		}

		std::ifstream shaderStream(filename, std::ios::in);
		if(!shaderStream.is_open()) {
			std::cout << filename << " 파일 읽기 오류" << std::endl;
			return 0;
		}
		std::string shaderCode;
		std::string Line = "";
		while(getline(shaderStream, Line)) {
			shaderCode += "\n" + Line;
		}
		shaderStream.close();

		const char* code = shaderCode.c_str();
		glShaderSource(shader, 1, &code, NULL);
		glCompileShader(shader);
		glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
		if (!compiled){
			GLint infoLen = 0;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);

			if (infoLen > 1){
				char* infoLog = new char[infoLen];
				glGetShaderInfoLog(shader, infoLen, NULL, infoLog);
				std::cout << "Shader compile 오류 " << infoLog << std::endl;
				delete infoLog;
			}
			glDeleteShader(shader);
			return 0;
		}


		return shader;
	};

	GLuint getShaderId(){
		return shaderId;
	};
	void bind() {
		glUseProgram(shaderId);
	}
	void unbind(){
		glUseProgram(0);
	};

private:

	GLuint shaderId;
	GLuint vertexShader;
	GLuint fragmentShader;

};