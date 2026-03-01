#pragma once
#include "Drawer.h"

class TerminalDrawer : public Drawer {

public:
    TerminalDrawer() : Drawer() {}

    void draw(const Circle& circle);
    void draw(const Rectangle& rectangle);

    virtual ~TerminalDrawer() {}
private:

};