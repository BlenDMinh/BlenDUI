#pragma once

#include "DrawUnit.h"

class Component {
protected:
    int x;
    int y;
public:
    Component(int x = 0, int y = 0) : x(x), y(y) {}
    ~Component() {}

    int GetX() const {
        return this->x;
    }

    int GetY() const {
        return this->y;
    }

    void SetX(int x) {
        this->x = x;
    }

    void SetY(int y) {
        this->y = y;
    }

    virtual void Draw(DrawUnit& buffer) {}
};