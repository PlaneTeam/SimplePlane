#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Character.hpp"

class Player :public Character {
    public:
        Player() { std::cout << "Player!" << std::endl; }
        virtual void move();
        virtual void shoot();
        virtual void beShooted();
        virtual void isDead();
};

#endif
