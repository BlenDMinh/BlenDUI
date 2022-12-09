#pragma once

#include "Component.h"
#include "DrawUnit.h"
#include "Text.h"

#include <string>

class ConsoleApp;

class TextBox : public Component {
protected:
    int width;
    int height;
    DrawUnit::Align hAlign;
    DrawUnit::Align vAlign;
public:
    Text text;
    
    TextBox() {}
    TextBox(int x, int y, std::string text, int boxWidth, int boxHeight, DrawUnit::Align hAlign = DrawUnit::Align::LEFT, DrawUnit::Align vAlign = DrawUnit::Align::TOP) : Component(x, y), width(boxWidth), height(boxHeight), hAlign(hAlign), vAlign(vAlign) {
        int t_x, t_y;
        if(hAlign == DrawUnit::Align::LEFT)
            t_x = x + 1;
        if(hAlign == DrawUnit::Align::CENTER)
            t_x = x + boxWidth / 2 - text.size() / 2;
        if(hAlign == DrawUnit::Align::RIGHT)
            t_x = x + boxWidth - 1 - text.size();

        if(vAlign == DrawUnit::Align::TOP)
            t_y = y + 1;
        if(vAlign == DrawUnit::Align::CENTER)
            t_y = y + boxHeight / 2;
        if(vAlign == DrawUnit::Align::BOTTOM)
            t_y = y + boxHeight - 1;
        this->text = Text(text, t_x, t_y);
    }
    int GetWidth() const {
        return this->width;
    }

    int GetHeight() const {
        return this->height;
    }

    DrawUnit::Align GetHAlignment() const {
        return this->hAlign;
    }

    DrawUnit::Align GetVAlignment() const {
        return this->vAlign;
    }

    virtual void Draw(DrawUnit& buffer) override {
        //Draw border
        for(int i = 1; i < this->width - 1; i++) {
            buffer.SetBuffer(x + i, y, 196);
            buffer.SetBuffer(x + i, y + this->height - 1, 196);
        }
        for(int i = 1; i < this->height - 1; i++) {
            buffer.SetBuffer(x, y + i, 179);
            buffer.SetBuffer(x + this->width - 1, y + i, 179);
        }
        buffer.SetBuffer(x, y, 474 % 256);
        buffer.SetBuffer(x, y + this->height - 1, 192);
        buffer.SetBuffer(x + this->width - 1, y, 191);
        buffer.SetBuffer(x + this->width - 1, y + this->height - 1, 473 % 256);
        //Draw text
        text.Draw(buffer);
    }
};