#pragma once
#include <string>
class Screen {
public:
    Screen(const Screen& _screen) = delete;

    static Screen& get();

    std::string& getPixels();

    void print();

    int getScreenWidth() const;
    int getScreenHeight() const;


private:

    Screen();
    int screenWidth{ 40 };
    int screenHeight{ 40 };
    std::string pixels{ std::string(screenWidth * screenHeight, ' ') };
};