#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#define PLAYER_INITIAL_HP 5
#define ENEMY_INITIAL_HP 3
class Character {
    public:
    	enum Bullet { player , enemy };
        Character() { std::cout << "Character!" << std::endl; }
        virtual ~Character();
        void setCoordinate(int,int);
        void setSpeed(int);
        void setHP(int);
        virtual void move();
        virtual void shoot();
        virtual void beShooted();
        virtual void isDead();
    private:
    	int x;
    	int y;
    	int HP;
    	int speed;
    	enum Bullet bullet;
    	bool is_dead;
};

#endif
