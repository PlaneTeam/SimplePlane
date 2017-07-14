#ifndef SCENE_MAP_HPP_
#define SCENE_MAP_HPP_

#include "Scene.hpp"

class SceneMap :public Scene {
  private:
    static Scene* instance;
    Sprite test;
    SceneMap() : test(0, 0, 12, 1, "A Test!!!") {}
    ~SceneMap() {}

  public:
    static Scene* getInstance() {
      if (instance == nullptr) {
        instance = new SceneMap();
      }
      return instance;
    }

    void update() {
      
    }
};
Scene* SceneMap::instance = nullptr;

#endif
