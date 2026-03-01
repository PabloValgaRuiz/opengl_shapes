#pragma once
#include "OpenGLShapeRenderer.h"
#include "Drawer.h"


class OpenGLDrawer : public Drawer {

public:
    OpenGLDrawer() = delete;

    OpenGLDrawer(OpenGLShapeRenderer* renderer);

    void draw(const Circle& circle);
    void draw(const Rectangle& rectangle);

private:
    OpenGLShapeRenderer* renderer;
};