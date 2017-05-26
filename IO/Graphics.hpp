#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&);               \
  void operator=(const TypeName&)

#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <vector>
#include "Window.hpp"
#include "SpriteBase.hpp"

using namespace std;
using namespace std::chrono;
class Graphics {
 public:
  void init() {
    sleepTime = 100;
    t1 = steady_clock::now();
    frameNum = 0;
    tagFrame = 0;
  }

  static void update() {
    //system("cls");
    //cerr << Graphics::getInstance()->getFrame() << endl;
    Graphics::getInstance()->controlFrame();
    Window::cursorDisable();
    Window::windowInfoDisable();
    Window::cleanWindow();
    for (std::vector<SpriteBase*>::iterator it = sprite.begin(); it != sprite.end(); it++) {
      (*it)->print();
    }
  }

  static Graphics* getInstance() {
    if (Ins == NULL) {
      Ins = new Graphics();
      Graphics::getInstance()->init();
    }
    return Ins;
  }

  int getFrame() { return frameNum; }

  int getsleepTime() { return sleepTime; }

  void setFrame(int num) {
    tagFrame = num;
    sleepTime = (1000 / (double)tagFrame);
  }

  void pushSprite(SpriteBase* s) {
    sprite.push_back(s);
  }

  void popSprite(SpriteBase* s) {
    for (std::vector<SpriteBase*>::iterator it = sprite.begin(); it != sprite.end(); it++) {
      if (*it == s) {
        sprite.erase(it);
        return;
      }
    }
  }

 private:
  DISALLOW_COPY_AND_ASSIGN(Graphics);
  Graphics() {}
  ~Graphics() {}
  void controlFrame() {
      steady_clock::time_point t2 = steady_clock::now();
      duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
      t1 = steady_clock::now();
        if (time_span.count() < (1 / (double)tagFrame)) {
            sleepTime++;
        } else {
            if(sleepTime > 1) sleepTime--;
        }
      frameNum = 1 / time_span.count();
    Sleep(sleepTime);
  }
  static Graphics* Ins;
  steady_clock::time_point t1;
  int sleepTime;
  int frameNum;
  int tagFrame;
  static std::vector<SpriteBase*> sprite;
};
Graphics* Graphics::Ins = NULL;
std::vector<SpriteBase*> Graphics::sprite;



#endif
