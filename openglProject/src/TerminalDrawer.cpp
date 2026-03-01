#include "TerminalDrawer.h"
#include "Screen.h"
#include "Circle.h"
#include "Rectangle.h"

void TerminalDrawer::draw(const Circle& circle)
{
    auto& pixels = Screen::get().getPixels();

    uint32_t screenWidth = Screen::get().getScreenWidth();
    uint32_t screenHeight = Screen::get().getScreenHeight();

    double radius = circle.getRadius();
    double x = circle.getX();
    double y = circle.getY();

    for (uint32_t i = 0; i < screenWidth; i++) {
        for (uint32_t j = 0; j < screenHeight; j++) {

            if ((i - x) * (i - x) + (j - y) * (j - y) < radius * radius)
                pixels[i * screenHeight + j] = '@';

        }
    }
}

void TerminalDrawer::draw(const Rectangle& rectangle)
{
    auto& pixels = Screen::get().getPixels();

    uint32_t screenWidth = Screen::get().getScreenWidth();
    uint32_t screenHeight = Screen::get().getScreenHeight();

    double width = rectangle.getWidth();
    double height = rectangle.getHeight();
    double x = rectangle.getX();
    double y = rectangle.getY();

    for (uint32_t i = 0; i < screenWidth; i++) {
        for (uint32_t j = 0; j < screenHeight; j++) {

            if ((((i > x - width) && (i < x + width)) && ((j > y - height) && (j < y + height))))
                pixels[i * screenHeight + j] = '@';

        }
    }
}
