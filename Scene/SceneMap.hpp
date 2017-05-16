#ifndef SCENE_MAP_HPP_
#define SCENE_MAP_HPP_
#include "Scene.hpp"
#include "../Character/Player.hpp"
#include "../Character/Enemy.hpp"

#include <vector>
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&);               \
  void operator=(const TypeName&)

class SceneMap :public Scene {
    public:
    void main() {
        Player p1;
        //Player p2;
        Enemy e1;
    }
    void addEnemy();
    void addBullet();
    void addScores();
    void timeCount();
    void printMap();
    void isOver();
    //input:改变player坐标，发射子弹？ 
    static SceneMap* getInstance();
    
    private:
    	int scores;
    	//time
    	bool gameOver;
        static SceneMap* _instance;
        vector<Bullet> bullet;
        vector<Enemy> enemy;
        SceneMap(){}//构造函数
        ~SceneMap() {}
        DISALLOW_COPY_AND_ASSIGN(SceneMap);
};

#endif
