#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include "IO.hpp"

class Character {
  private:
    Sprite sprite;
  
  public:
    enum direct { UP, DOWN, LEFT, RIGHT };
    Character(int real_x, int real_y, string path) : sprite(real_x, real_y, path) {}
    void move(direct d) {
      switch (d) {
        case UP: sprite.setRealY(sprite.getRealY()-1); break;
        case DOWN: sprite.setRealY(sprite.getRealY()+1); break;
        case LEFT: sprite.setRealX(sprite.getRealX()-1); break;
        case RIGHT: sprite.setRealX(sprite.getRealX()+1); break;
      }
    }
};

#endif
