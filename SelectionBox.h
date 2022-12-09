#include "TextBox.h"

class SelectionBox : public TextBox {
private:
    bool isSelected = false;
public:
    SelectionBox() {}
    SelectionBox(int x, int y, std::string text, int boxWidth, int boxHeight, DrawUnit::Align hAlign = DrawUnit::Align::LEFT, DrawUnit::Align vAlign = DrawUnit::Align::TOP) : TextBox(x, y, text, boxWidth, boxHeight, hAlign, vAlign) {}
    ~SelectionBox() {}

    void SetSelection(bool status) {
        this->isSelected = status;
    }

    void Draw(DrawUnit& buffer) override {
        //Draw border
        for(int i = 1; i < this->width - 1; i++) {
            if(this->isSelected) {
                buffer.SetBuffer(x + i, y, 205);
                buffer.SetBuffer(x + i, y + this->height - 1, 205);
            } else {
                buffer.SetBuffer(x + i, y, 452 % 256);
                buffer.SetBuffer(x + i, y + this->height - 1, 452 % 256);
            }
        }
        for(int i = 1; i < this->height - 1; i++) {
            if(this->isSelected) {
                buffer.SetBuffer(x, y + i, 186);
                buffer.SetBuffer(x + this->width - 1, y + i, 186);
            } else {
                buffer.SetBuffer(x, y + i, 435 % 256);
                buffer.SetBuffer(x + this->width - 1, y + i, 435 % 256);
            }
        }
        if(this->isSelected) {
            buffer.SetBuffer(x, y, 174);
            buffer.SetBuffer(x, y + this->height - 1, 174);
            buffer.SetBuffer(x + this->width - 1, y, 175);
            buffer.SetBuffer(x + this->width - 1, y + this->height - 1, 175);
        } else {
            buffer.SetBuffer(x, y, 474 % 256);
            buffer.SetBuffer(x, y + this->height - 1, 192);
            buffer.SetBuffer(x + this->width - 1, y, 191);
            buffer.SetBuffer(x + this->width - 1, y + this->height - 1, 473 % 256);
        }
        //Draw text
        text.Draw(buffer);
    }
};
