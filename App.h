#include "UI/Scene.h"

#include<string>
#include<map>
#include<exception>

class App {
private:
    static std::map<std::string, Scene*> loadedScenes;

    Scene *scene = nullptr;
    static App* instance;

    App(std::string title = "My App", int width = 120, int height = 30) {

    }

    ~App() {
        delete scene;
    }
public:
    static void InitApp(std::string title = "My App", int width = 120, int height = 30) {
        App::instance = new App(title, width, height);
    }

    static App* GetRunningApp() {
        if(App::instance == NULL)
            throw "App is not initialized!";
        return App::instance;
    }

    static void AddScene(Scene* scene, std::string loadString, bool defaultScene = false) {
        loadedScenes[loadString] = scene;
        if(defaultScene) {
            try {
                App::GetRunningApp()->scene = scene;
            } catch(const char* err) {
                std::cerr << err << std::endl;
                std::system("pause");
            }
        }
    }

    static void SetScene(std::string sceneName) {
        if(loadedScenes.find(sceneName) == loadedScenes.end())
            throw "Scene with name: " + sceneName + " not loaded!\n";
        App::GetRunningApp()->scene = loadedScenes[sceneName];
        App::GetRunningApp()->scene->Start();
    }

    static Scene* GetScene(std::string sceneName) {
        if(loadedScenes.find(sceneName) == loadedScenes.end())
            throw "Scene with name: " + sceneName + " not loaded!\n";
        return loadedScenes[sceneName];
    }

    void SetScene(Scene* scene) {
        if(this->scene != nullptr) {
            this->scene->Clear();
            delete this->scene;
        }
        this->scene = scene;
        this->scene->Start();
    }

    void Run() {
        scene->Start();
        while(true) {
            if(scene == nullptr) {
                std::cout << "Scene is null!\n";
                system("pause");
                continue;
            }
            scene->Display();
            scene->Update(scene->GetKey());
        }
    }
};

App* App::instance = NULL;
std::map<std::string, Scene*> App::loadedScenes = std::map<std::string, Scene*>();