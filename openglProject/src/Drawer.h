#pragma once

class Circle;
class Rectangle;

class Drawer {
public:
    virtual void draw(const Circle& circle) = 0;
    virtual void draw(const Rectangle& rectangle) = 0;

    virtual ~Drawer() {}
};