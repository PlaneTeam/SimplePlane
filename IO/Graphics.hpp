#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&);               \
  void operator=(const TypeName&)

#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>

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
      system("cls");
    cerr << Graphics::getInstance()->getFrame() << endl;
    Graphics::getInstance()->controlFrame();
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
};
Graphics* Graphics::Ins = NULL;

#endif
