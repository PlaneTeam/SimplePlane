#ifndef SCENE_HPP_
#define SCENE_HPP_

class Scene;

Scene* G_scene = nullptr;
Scene* G_old_scene = nullptr;

class Scene {
  public:
    Scene(){}
    virtual ~Scene(){}
		virtual void update() = 0;
		void main() {
			while (true) {
        Graphics::update();
        Input::update();
        update();
        if (G_scene != this) {
          break;
        }
      }
		}
};

class SceneStart;
class SceneMap;

#endif
