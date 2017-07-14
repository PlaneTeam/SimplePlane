#ifndef SCENE_START_HPP_
#define SCENE_START_HPP_

#include "Scene.hpp"
#include "SceneMap.hpp"

class SceneStart :public Scene {
  private:
    static Scene* instance;
    Sprite index_start, index_quit;
    bool index = true;
    SceneStart() : index_start(35, 20, 10, 1, "START GAME"), index_quit(38, 22, 4, 1, "QUIT") {
      index_quit.bitmap().setAllForeground(0x06);
    }
    ~SceneStart() {}

  public:
    static Scene* getInstance() {
      if (instance == nullptr) {
        instance = new SceneStart();
      }
      return instance;
    }

    void update() {
      if (Input::press(Input::ENTER)) {
        if (index) {
          G_scene = SceneMap::getInstance();
        } else {
          G_scene = nullptr;
        }
      } else if (Input::press(Input::W)) {
        index_start.bitmap().setAllForeground(0x07);
        index_quit.bitmap().setAllForeground(0x06);
        index = true;
      } else if (Input::press(Input::S)) {
        index_start.bitmap().setAllForeground(0x06);
        index_quit.bitmap().setAllForeground(0x07);
        index = false;
      }
    }
};
Scene* SceneStart::instance = nullptr;

#endif
