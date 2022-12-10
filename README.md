# BlenDUI - Console UI Library for C++
A simple headers C++ library for creating your UI directly on Windows's command prompt.
## Installation
Extract everything into your project file and include ```App.h``` file.
## Usage
### Initialize App
Before doing anything you will first need to initialize the App by the following code:
```C++
App::InitApp("Demo UI Library");
```
**"Demo UI Libary"** is your App name, you can change this to something else
### Creating your Scene
You will first need to create a class for a scene, which inherit from class Scene like this:
```C++
class Demo : public Scene {
private:

public:
    Demo(int width = 120, int height = 30) : Scene(width, height) {}
    virtual ~Demo() {}

    void Start() override {

    }

    void Update(int input = -1) override {

    }
};
```
This is where you add the components (Text, TextBox, SelectionBox, ...) and create the logic code for them

You will want to put the code you want to run from the starting of your scene inside the ```Start()``` function. ```Start``` function will be executed once everytime the scene get display on your screen.

While the scene is displaying, everytime you pressed a key, the keycode will be sent to ```Update(int input)``` function. The ```Update(int input)``` will then be called once and the scene get refreshed (drawing the components once again).

For example: Let's create a Scene where there're a TextBox "Hello World" and a SelectionBox which tell you to press Enter to switch to a new Scene

**Demo Scene:**
```C++
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
    }
};
```
**And the NextScene Scene:**
```C++
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

    }
};
```
Once everything is done, you will need to add the instance of your scenes to the App:
```C++
Demo *demo = new Demo;
App::AddScene(demo, "demo", true);

NextScene *next = new NextScene;
App::AddScene(next, "NextScene");
```
You will now ready, all you need to do now is call ```Run()``` function from your app instance in your ```main()```
```C++
App* app = App::GetRunningApp();
app->Run();
```
Hurray, you have created your first 2 Scenes:
![demo](https://github.com/BlenDMinh/BlenDUI/blob/main/DemoImages/demo.jpg)
![NextScene](https://github.com/BlenDMinh/BlenDUI/blob/main/DemoImages/demoNext.jpg)
### Text
### TextBox
### SelectionBox
