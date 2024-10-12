#include "drawableObject.h"


DrawableObject::DrawableObject(Model* model, ShaderProgram* shaderProgram) {
	this->shaderProgram = shaderProgram;
	this->model = model;
}

void DrawableObject::draw(GLenum mode) {
	shaderProgram->activate();
	model->draw(mode);
	shaderProgram->deactivate();
}