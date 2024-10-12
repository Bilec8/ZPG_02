#pragma once
#include "drawableObject.h"
#include <vector>

using namespace std;

class Scene {
private:
    vector<DrawableObject*> objects;
public:
    void addObject(DrawableObject* object);
    void render();
};