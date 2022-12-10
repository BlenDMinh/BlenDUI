#include "App.h"

class Demo : public Scene {
private:
    TextBox *helloWord;
    SelectionBox *next;
public:
    Demo(int width = 120, int height = 30) : Scene(width, height) {}
    virtual ~Demo() {}

    void Start() override {
        helloWord = new TextBox(10, 5, "Hello World", 100, 11, DrawUnit::Align::CENTER, DrawUnit::Align::CENTER);
        next = new SelectionBox(10, 20, "Enter to go to Welcome Scene", 100, 3, DrawUnit::Align::CENTER);
        next->SetSelection(true);
        this->AddComponent(helloWord);
        this->AddComponent(next);
    }

    void Update(int input = -1) override {
        if(input == 13) // Enter
            App::SetScene("NextScene");
        if(input == 27) // ESC
            exit(0);
    }
};

class NextScene : public Scene {
private:
    TextBox *welcome;
public:
    NextScene(int width = 120, int height = 30) : Scene(width, height) {}
    virtual ~NextScene() {}

    void Start() override {
        welcome = new TextBox(10, 5, "Welcome to BlenDUI", 100, 3, DrawUnit::Align::CENTER, DrawUnit::Align::CENTER);
        AddComponent(welcome);
    }

    void Update(int input = -1) override {
        if(input == 27) // ESC
            App::SetScene("demo");
    }
};

void InitApp() {
    App::InitApp("Demo UI Library");
}

void InitScenes() {
    Demo *demo = new Demo;
    App::AddScene(demo, "demo", true);

    NextScene *next = new NextScene;
    App::AddScene(next, "NextScene");
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