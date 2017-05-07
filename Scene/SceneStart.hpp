#ifndef SCENE_START_HPP_
#define SCENE_START_HPP_

#include "Scene.hpp"
#include "SceneMap.hpp"

class SceneStart :public Scene {
    public:
    void main() {
        SceneMap scene;
        scene.main();
    }
};

#endif
