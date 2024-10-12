#include "shader.h"
#include <iostream>

Shader::Shader(const std::string& shaderSource, GLenum shaderType) {
    shaderID = glCreateShader(shaderType);
    compileShader(shaderSource, shaderType);
}

void Shader::compileShader(const std::string& shaderSource, GLenum shaderType) {
    const char* source = shaderSource.c_str();
    glShaderSource(shaderID, 1, &source, nullptr);
    glCompileShader(shaderID);

    GLint success;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
    if (!success) {
        GLchar infoLog[512];
        glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
}

void Shader::attachToProgram(GLuint programID) const {
    glAttachShader(programID, shaderID);
}