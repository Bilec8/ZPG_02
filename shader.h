#pragma once
#include <GL/glew.h>
#include <string>

class Shader {
private:
    GLuint shaderID; 
    GLenum shaderType;

    void compileShader(const std::string& shaderSource, GLenum shaderType);
public:
    void attachToProgram(GLuint programID) const;
    Shader(const std::string& shaderSource, GLenum shaderType);;
};
