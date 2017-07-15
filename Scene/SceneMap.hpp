#ifndef SCENE_MAP_HPP_
#define SCENE_MAP_HPP_

#include "Player.hpp"
#include "Scene.hpp"

class SceneMap :public Scene {
  private:
    static Scene* instance;
    Player player;
    SceneMap() : player(0, 0, "./Sprite/player.pbm") {}
    ~SceneMap() {}

  public:
    static Scene* getInstance() {
      if (instance == nullptr) {
        instance = new SceneMap();
      }
      return instance;
    }

    void update() {
      player.update();
    }
};
Scene* SceneMap::instance = nullptr;

#endif
