# CPPGSS -- Scene篇

## 介绍

在CPPGSS里面，Scene是游戏实现场景类的重要基类

CPPGSS的机制便是循环执行场景类的main()方法，达到游戏运行的效果

## 模板

```c++
#ifndef SCENE_TEST_HPP_
#define SCENE_TEST_HPP_

#include "Scene.hpp"

class SceneTest : public Scene {
  private:
    static Scene* instance;
    SceneTest() {}
    ~SceneTest() {}

  public:
    static Scene* getInstance() {
      if (instance == nullptr) {
        instance = new SceneTest();
      }
      return instance;
    }

    void update() {
      // 自定义代码
    }
};
Scene* SceneTest::instance = nullptr;

#endif
```

## 运行

场景类的实现是通过继承基类Scene以达到实现所有类统一的效果，类中的虚函数update()是循环调用的函数，游戏的所有操作都编写在其中。

而移动场景的方式是通过修改G_scene的值

以G_开头的变量为CPPGSS中的全局变量，通过修改该变量的值可以使得场景发生变化

update()函数我们可以这样写

```c++
// 按下M键切换到SceneMap场景
// 按下Q键退出程序
void update() {
  if (Input::press(Input::M)) {
    G_scene = SceneMap::getInstance();
  } else if (Input::press(Input::Q)) {
    G_scene = nullptr;
  }
}
```

在Scene类中，我们这样定义main()

```c++
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
```

当G_scene不为该类时，我们将结束循环，程序则跳转回主函数main()

```c++
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
```

则会删除原有的Scene类的实例，并执行新场景的main方法

## 安全性

单线程下相对安全
