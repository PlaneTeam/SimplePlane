#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include "SceneMap.hpp"
#define PLAYER_INITIAL_HP 5
#define ENEMY_INITIAL_HP 3

struct Bullet {
	public:
	    Bullet(int x,int y): x(x), y(y) ;
	    ~Bullet();
	    void move();
	    void disapprear();
	    pair<int,int> getCoordinate();
	private:
		int x;
		int y;
		const int speed=2;
}; 
class Character {
    public:
        Character();
        virtual ~Character();
        void setCoordinate(int x_,int y_){ x=x_ ; y=y_; }
        void setSpeed(int s){ s=speed; }
        void setHP(int hp){ hp=HP; }
        virtual void shoot(SceneMap* );
        virtual void beShooted();
        virtual void isDead(SceneMap* );
    private:
    	int x;
    	int y;
    	int HP;
    	int speed;
    	const char bullet;
    	bool is_dead;
};

#endif
