#pragma once
#include <GL/glew.h>
#include "scene.h"
#include <iostream>


//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
#include <GLFW/glfw3.h>

class Application {
private:
    GLFWwindow* window;
    Scene scene;

    int width;
    int height;
    const char* title;

    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
public:
    Application(int width, int height, const char* title);
    void run();
    void addDrawableObject(DrawableObject* object);
};