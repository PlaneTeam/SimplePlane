#ifndef SCENE_START_HPP_
#define SCENE_START_HPP_

#include "Scene.hpp"

class SceneStart :public Scene {
    public:
    void main() {
        while (true) {
            Graphics::update();
            Input::update();
            if (Input::trigger(Input::Q)) {
                std::cout << "quit" << std::endl;
            }
        }
    }
};

#endif
