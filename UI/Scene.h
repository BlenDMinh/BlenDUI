#pragma once

#include "SelectionBox.h"
#include "TextBox.h"
#include "DrawUnit.h"

#include <windows.h>
#include <conio.h>

class Scene {

private:
    std::vector<Component *> components;
    DrawUnit buffer;

    void ClearComponents() {
        for(Component* component : components)
            if(component != nullptr)
                delete component;
        components.clear();
    }

protected:
    int sceneWidth;
    int sceneHeight;
    int curX;
    int curY;
public:
    Scene(int width = 120, int height = 30) {
        HWND console = GetConsoleWindow();
        RECT r;
        GetWindowRect(console, &r);
        MoveWindow(console, r.left, r.top, width, height, TRUE);

        this->sceneWidth = width;
        this->sceneHeight = height;

        this->Clear();

        this->buffer = DrawUnit(width, height);   
    }
    virtual ~Scene() {
        for(Component* component : components)
            if(component != nullptr)
                delete component;
        components.clear();
    }

    void AddComponent(Component * component) {
        this->components.push_back(component);
    }

    void Display() {
        Clear();
        this->buffer.ClearBuffer();
        for(Component *component : components)
            component->Draw(this->buffer);
        this->buffer.Display();
    }

    void Clear() {
        this->buffer = DrawUnit(this->sceneWidth, this->sceneHeight);
        std::system("cls");
    }

    int GetKey() {
        int get_char = _getch();
        if(get_char == 224)
            get_char += _getch();
        return get_char;
    }

    virtual void Start() {}

    virtual void Update(int input = -1) {}

    friend class App;
};