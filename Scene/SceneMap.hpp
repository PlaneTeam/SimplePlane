#ifndef SCENE_MAP_HPP_
#define SCENE_MAP_HPP_
#include "Scene.hpp"
#include "../Character/Player.hpp"
#include "../Character/Enemy.hpp"

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
    void addScores();
    void timeCount();
    void printMap();
    bool isOver();
    static SceneMap* getInstance();
    
    private:
    	int scores;
    	//time
    	bool gameOver;
        static SceneMap* _instance;
        SceneMap(){}//¹¹Ôìº¯Êý
        ~SceneMap() {}
        DISALLOW_COPY_AND_ASSIGN(SceneMap);
};

#endif
