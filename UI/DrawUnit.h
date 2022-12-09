#pragma once

#include "TextBox.h"

#include<string>
#include<vector>
#include<iostream>

class DrawUnit {
private:
    int width;
    int height;
    std::vector<std::string> buffer;
public:
    enum Align {
        LEFT,
        CENTER,
        RIGHT,
        TOP,
        BOTTOM
    };
    DrawUnit(int width = 120, int height = 30) : width(width), height(height) {
        buffer = std::vector<std::string>(height, std::string(width, ' '));
    }
    ~DrawUnit() {
        buffer.clear();
    }

    void ClearBuffer() {
        this->buffer.clear();
        this->buffer = std::vector<std::string>(this->height, std::string(this->width, ' '));
    }

    void Display() {
        std::string screen = "";
        for(std::string line : buffer)
            screen += line + "\n";
        std::cout << screen;
    }

    void SetBuffer(int x, int y, char c) {
        if(this->buffer.size() <= y || this->buffer[y].size() <= x)
            return;
        this->buffer[y][x] = c;
    }

    int GetWidth() const {
        return this->width;
    }

    int GetHeight() const {
        return this->height;
    }
};