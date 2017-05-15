#include "Graphics.hpp"

#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <iostream>
using namespace std;

Graphics* Graphics::Ins = NULL;
void Graphics::init() {
  sleepTime = 10;
  tempNum = 0;
  frameNum = 0;
  lastTime = 0;
  toFrame = 40;
}
void Graphics::update() {
  system("cls");
  cout << Graphics::getInstance()->getFrame() << endl;
  Graphics::getInstance()->controlFrame();
}

Graphics* Graphics::getInstance() {
  if (Ins == NULL) {
    Ins = new Graphics();
    Graphics::getInstance()->init();
  }
  return Ins;
}

int Graphics::getFrame() { return frameNum; }

int Graphics::getsleepTime() { return sleepTime; }

void Graphics::setFrame(int num) {
  toFrame = num;
  sleepTime = (1000 / (double)toFrame)/2;
}
void Graphics::controlFrame() {
  int nowTime = time((time_t*)NULL);
  if (nowTime != lastTime) {
    frameNum = tempNum;
    tempNum = 0;
    lastTime = nowTime;
    if (frameNum < toFrame) {
      if(sleepTime != 1) sleepTime--;
    } else {
      sleepTime++;
    }
  }
  Sleep(sleepTime);
  tempNum++;
}
