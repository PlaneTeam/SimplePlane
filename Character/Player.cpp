#include "Player.hpp"

Player::Player(): Character() {
	setHP(PLAYER_INITIAL_HP);
	setSpeed(1);
	setCoordinate(0,0);//��ͼ�м䣿 
	bullet='O'; 
	is_dead=false;
}
void Player::move(int x_, int y_){//scene����input�������ƶ�x��y 
	x+=x_;
	y+=y_;
}
void Player::shoot(SceneMap* map){
}
void Player::beShooted(){
	
}
void Player::isDead(SceneMap* map){
}
