#include "VAO.h"

void VAO::bind() {
	glBindVertexArray(ID);
}

void VAO::unbind() {
	glBindVertexArray(0);
}

void VAO::generateVAO(){
	glGenVertexArrays(1, &ID);
}