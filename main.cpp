#include <iostream>
#include "IO.hpp"
#include "SceneStart.hpp"

int main() {
    Input::init();
    Graphics::getInstance()->setFrame(40);
    G_scene = SceneStart::getInstance();
    G_old_scene = G_scene;
    while (G_scene != nullptr) {
        if (G_old_scene != G_scene) {
            delete G_old_scene;
            G_old_scene = G_scene;
        } 
        G_scene->main();
    }
    delete G_scene;
}
