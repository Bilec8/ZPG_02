#pragma once
#include "shaderProgram.h"
#include "model.h"

class  DrawableObject {
private:
	ShaderProgram* shaderProgram;
	Model* model;

public:
	DrawableObject(Model* model, ShaderProgram* shaderProgram);
	void draw(GLenum mode);
};