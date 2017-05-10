#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

class Character {
    public:
    	enum Bullet{player,enemy};
        Character(){ std::cout << "Character!" << std::endl; }
        virtual ~Character();
        virtual void move();
        virtual void shoot();
        virtual void beShooted();
        void isDead();
    private:
    	int HP;
    	enum Bullet bullet;
};

#endif
