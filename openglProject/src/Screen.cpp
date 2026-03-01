#include <iostream>

#include "Screen.h"

Screen& Screen::get() {
    static Screen screen{};
    return screen;
}

std::string& Screen::getPixels() { return pixels; }

void Screen::print() {
    
    system("CLS");
    std::cout << "\n\n";
    for (uint32_t i = 0; i < screenWidth; i++) {
        for (uint32_t j = 0; j < screenHeight; j++) {
            std::cout << " " << pixels[i * screenHeight + j];
            pixels[i * screenHeight + j] = ' ';
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    std::cout.flush();

}

int Screen::getScreenWidth() const { return screenWidth; }

int Screen::getScreenHeight() const { return screenHeight; }

Screen::Screen() {}
