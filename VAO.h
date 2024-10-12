#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h> 

class VAO
{
private:
	GLuint ID;
public:
	void generateVAO();
	void bind();
	void unbind();
};