#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
TypeName(const TypeName&);               \
void operator=(const TypeName&)

class Graphics {
public:
  void init();
  static void update();
  static Graphics* getInstance();
  int getFrame();
  int getsleepTime();
  void setFrame(int num);
private:
  DISALLOW_COPY_AND_ASSIGN(Graphics);
  Graphics(){}
  ~Graphics(){}
  void controlFrame();
  static Graphics* Ins;
  int toFrame;
  int sleepTime;
  int tempNum;
  int frameNum;
  int lastTime;
};

#endif
