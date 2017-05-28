#include "Enemy.hpp"

Enemy::Enemy(): Character() {
	setHP(ENEMY_INITIAL_HP);
	setSpeed(1);
	setCoordinate(x,0); // 随机x 
	is_dead = false;
}
void Enemy::move(){
	y++;
}
void Enemy::shoot(SceneMap* map){
	map->addBullet();
}
void Enemy::beShooted(){
	HP--;
    if(HP == 0)
        isDead(map);
}
void Enemy::isDead(SceneMap* map){
	map_[x][y] = ' '; // 销毁此Enemy
}
