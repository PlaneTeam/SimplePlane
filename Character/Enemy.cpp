Enemy::Enemy()
	:Character(){
		//�˴�Ӧ����������������� 
	setCoordinate(x, y);
    setSpeed(1);
    setHP(ENEMY_INITIAL_HP);	
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
		isDead();
}
void Enemy::isDead(SceneMap* map){
	map[x][y] == ' ';
	map->deleteEnemy();
}
