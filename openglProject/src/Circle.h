#pragma once
#include<memory>

#include "Shape.h"
#include "Drawer.h"

class Circle : public Shape {
public:
    Circle() = delete;
    Circle(std::unique_ptr<Drawer> drawer);
    Circle(double _radius, double _x, double _y, std::unique_ptr<Drawer> drawer);

    virtual void draw() {
        drawer->draw(*this);
    }

    double getRadius() const;
    double getX() const;
    double getY() const;
    double& getRadius();
    double& getX();
    double& getY();

private:
    double radius{ 40 / 4 };
    double x{ 40 / 2 }, y{ 40 / 2 };

    std::unique_ptr<Drawer> drawer;

};