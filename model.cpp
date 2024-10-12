#include "model.h"

Model::Model(const GLfloat* data, GLsizeiptr size) {
    vao = new VAO();
    vbo = new VBO();

    this->count = size / (3 * sizeof(float));

	vbo->generateVBO(data, size);
    vao->generateVAO();
}

void Model::attribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer) {
	vao->bind();
	vbo->bind();

    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
    glEnableVertexAttribArray(index);

    vbo->unbind();
    vao->unbind();
}

void Model::draw(GLenum mode) {
	vao->bind();
	glDrawArrays(mode, 0, this->count);
	vao->unbind();
}