#pragma once
#include <GL/glew.h>
#include "shader.h"

class ShaderProgram {
private:
	GLuint ID;

    void linkProgram(const Shader& vertexShader, const Shader& fragmentShader);
public:
	ShaderProgram();

	void activate();
	void deactivate();
	void compileShaderProgram(const char* vertexShader, const char* fragmentShader);
    void checkErrors(const char* vertexShaderFile, const char* fragmentShaderFile);
};