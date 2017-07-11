#include "Player.hpp"

Player::Player(): Character() {
	setHP(PLAYER_INITIAL_HP);
	setSpeed(1);
	setCoordinate(0,0);//地图中间？ 
	bullet='O'; 
	is_dead=false;
}
void Player::move(int x_, int y_){//scene接受input，调用移动x，y 
	x+=x_;
	y+=y_;
}
void Player::shoot(SceneMap* map){
	map->addBullet();
}
void Player::beShooted(){
	
}
void Player::isDead(SceneMap* map){
	map->isOver();
}
