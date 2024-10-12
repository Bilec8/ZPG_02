#include "scene.h"

void Scene::addObject(DrawableObject* object) {
    objects.push_back(object);
}

void Scene::render() {
    for (auto object : objects) {
        object->draw(GL_TRIANGLES);
    }
}
