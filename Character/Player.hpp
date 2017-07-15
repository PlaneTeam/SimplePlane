#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Character.hpp"

class Player :public Character {
  public:
    Player(int real_x, int real_y, string path) : Character(real_x, real_y, path) {}
    void update();
};

#endif
