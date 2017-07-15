#include <iostream>
#include "IO.hpp"
#include "SceneStart.hpp"

int main() {
  Input::init();
  int var;
  cout << "Input the frame: ";
  cin >> var;
  cin.get();
  Sleep(200);
  cin.get();
  Graphics::getInstance()->setFrame(var);
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
