#include "shaderProgram.h"
#include <stdio.h>
#include <iostream>
#include <cstdlib>

ShaderProgram::ShaderProgram() {
	ID = glCreateProgram();
}

void ShaderProgram::activate() {
	glUseProgram(ID);
}

void ShaderProgram::deactivate() {
	glUseProgram(0);
}

void ShaderProgram::compileShaderProgram(const char* vertexShaderSrc, const char* fragmentShaderSrc) {
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSrc, nullptr);
	glCompileShader(vertexShader);

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSrc, nullptr);
	glCompileShader(fragmentShader);

	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);

    checkErrors(vertexShaderSrc, fragmentShaderSrc);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void ShaderProgram::checkErrors(const char* vertexShaderFile, const char* fragmentShaderFile) {
    GLint status;
    glGetProgramiv(ID, GL_LINK_STATUS, &status);
    if (status == GL_FALSE)
    {
        GLint infoLogLength;
        glGetProgramiv(ID, GL_INFO_LOG_LENGTH, &infoLogLength);
        GLchar* strInfoLog = new GLchar[infoLogLength + 1];
        glGetProgramInfoLog(ID, infoLogLength, NULL, strInfoLog);
        printf("Shaders: %s | %s", vertexShaderFile, fragmentShaderFile);
        fprintf(stderr, "Linker failure: %s\n", strInfoLog);
        delete[] strInfoLog;
        exit(EXIT_FAILURE);
    }
}

void ShaderProgram::linkProgram(const Shader& vertexShader, const Shader& fragmentShader) {
    vertexShader.attachToProgram(ID);
    fragmentShader.attachToProgram(ID); 
    glLinkProgram(ID);

    GLint success;
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(ID, 512, nullptr, infoLog);
        std::cerr << "ERROR::SHADER_PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
}