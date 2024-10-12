#pragma once

#include "VAO.h"
#include "VBO.h"

class Model {
private:
    VAO* vao;
	VBO* vbo;
	int count;

public:
	Model(const GLfloat* data, GLsizeiptr size);
	void attribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);
	void draw(GLenum mode);
};

