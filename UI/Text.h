#pragma once

#include "Component.h"
#include "DrawUnit.h"

#include <string>


class Text : public Component{
public:
    std::string text;
    Text(std::string text = "", int x = 0, int y = 0) : text(text), Component(x, y) {}
    ~Text() {}

    void Draw(DrawUnit& buffer) override {
        int line = 0;
        for(int i = 0, tX = i; i < text.size(); i++, tX++) {
            if(text[i] == '\n') {
                line++;
                tX = -1;
                continue;
            }
            buffer.SetBuffer(x + tX, y + line, text[i]);
        }
    }

    void SetText(std::string text) {
        this->text = text;
    }
};