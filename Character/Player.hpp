#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Character.hpp"

class Player :public Character {
    public:
        Player();
        void move(int, int);
        virtual void shoot(SceneMap* );
        virtual void beShooted();
        virtual void isDead(SceneMap* );
};

#endif
