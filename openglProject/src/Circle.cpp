#include "Circle.h"

Circle::Circle(std::unique_ptr<Drawer> drawer)
	: drawer(std::move(drawer)) {}

Circle::Circle(double _radius, double _x, double _y, std::unique_ptr<Drawer> drawer)

	: radius{ _radius }, x{ _x }, y{ _y }, drawer(std::move(drawer)) {}

double Circle::getRadius() const
{
	return radius;
}

double Circle::getX() const
{
	return x;
}

double Circle::getY() const
{
	return y;
}

double& Circle::getRadius()
{
	return radius;
}

double& Circle::getX()
{
	return x;
}

double& Circle::getY()
{
	return y;
}
