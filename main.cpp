// main.cpp
#include "Application.h"
#include "Model.h"
#include "ShaderProgram.h"
#include "drawableObject.h"

const char* vertex_shader =
"#version 330\n"
"layout(location=0) in vec3 vp;"
"void main () {"
"     gl_Position = vec4 (vp, 1.0);"
"}";

const char* fragment_shader =
"#version 330\n"
"out vec4 frag_colour;"
"void main () {"
"     frag_colour = vec4 (0.5, 0.0, 0.5, 1.0);"
"}";

float points[] = {
    0.0f,  0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
   -0.5f, -0.5f, 0.0f
};


int main() {
    Application app(800, 600, "OpenGL Application");

    ShaderProgram shaderProgram;
    shaderProgram.compileShaderProgram(vertex_shader, fragment_shader);

    Model model(points, sizeof(points));
    model.attribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    DrawableObject drawable(&model, &shaderProgram);
    app.addDrawableObject(&drawable);

    app.run();

    return 0;
}
