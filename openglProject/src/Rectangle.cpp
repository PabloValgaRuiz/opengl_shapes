#include "Rectangle.h"


Rectangle::Rectangle(std::unique_ptr<Drawer> drawer)
    : drawer(std::move(drawer)){}

Rectangle::Rectangle(double _width, double _height, double _x, double _y, std::unique_ptr<Drawer> drawer)
    : width{ _width }, height{ _height }, x{ _x }, y{ _y }, drawer( std::move(drawer) ) {}

double Rectangle::getWidth() const { return width; }
double Rectangle::getHeight() const { return height; }
double Rectangle::getX() const { return x; }
double Rectangle::getY() const { return y; }

double& Rectangle::getWidth()
{
    return width;
}
double& Rectangle::getHeight()
{
    return height;
}
double& Rectangle::getX()
{
    return x;
}
double& Rectangle::getY()
{
    return y;
}