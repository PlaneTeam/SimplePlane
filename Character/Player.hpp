#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "character.hpp"

class Player :public Character {
    public:
    Player() { std::cout << "Player!" << std::endl; }
};

#endif
