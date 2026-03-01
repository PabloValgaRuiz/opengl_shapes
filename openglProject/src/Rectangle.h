#pragma once
#include <memory>

#include "Shape.h"
#include "Drawer.h"

class Rectangle : public Shape {

public:

    Rectangle() = delete;
    
    Rectangle(std::unique_ptr<Drawer> drawer);

    Rectangle(double _width, double _height, double _x, double _y, std::unique_ptr<Drawer> drawer);

    virtual void draw() {
        drawer->draw(*this);
    }

    double getWidth() const;
    double getHeight() const;
    double getY() const;
    double getX() const;

    double& getWidth();
    double& getHeight();
    double& getY();
    double& getX();

private:

    double width{ 40 / 2 }, height{ 40 / 2 };
    double x{ 40 / 2 }, y{ 40 / 2 };

    std::unique_ptr<Drawer> drawer;

};