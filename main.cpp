#include "App.h"

class Demo : public Scene {
private:
    TextBox* helloWord;
public:
    Demo(int width = 120, int height = 30) : Scene(width, height) {}
    virtual ~Demo() {}

    void Start() override {
        helloWord = new TextBox(10, 5, "Hello World", 100, 11, DrawUnit::Align::CENTER, DrawUnit::Align::CENTER);
        this->AddComponent(helloWord);
    }

    void Update(int input = -1) override {

    }
};

void InitApp() {
    App::InitApp("Demo UI Library");
}

void InitScenes() {
    Demo *demo = new Demo;
    App::AddScene(demo, "demo", true);
}

void Run() {
    App* app = App::GetRunningApp();
    app->Run();
    system("pause");
}

int main() {
    InitApp();
    InitScenes();
    Run();
}