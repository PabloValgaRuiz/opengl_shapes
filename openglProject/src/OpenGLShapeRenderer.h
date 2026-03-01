#pragma once

#include <vector>

#include "Rectangle.h"
#include "Circle.h"

class OpenGLShapeRenderer {
private:
    unsigned int rectangleCount{ 0 };
    std::vector<float> rectangleVertexBuffer{};
    std::vector<unsigned int> rectangleIndexBuffer{};

    unsigned int circleCount{ 0 };
    std::vector<float> circleVertexBuffer{};
    std::vector<unsigned int> circleIndexBuffer{};

public:
    OpenGLShapeRenderer();

    void addShape(const Circle& circle);
    void addShape(const Rectangle& rectangle);

    void render();
};