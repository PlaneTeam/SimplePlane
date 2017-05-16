#ifndef ENEMY_HPP_
#define ENEMY_HPP_

#include "Character.hpp"

class Enemy :public Character {
    public:
        Enemy() { std::cout << "Enemy!" << std::endl; }
        virtual void move();
        virtual void shoot();
        virtual void beShooted();
        virtual void isDead();
};

#endif
