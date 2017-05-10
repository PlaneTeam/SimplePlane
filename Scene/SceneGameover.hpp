#ifndef SCENE_GAMEOVER_HPP_
#define SCENE_GAMEOVER_HPP_

#include "Scene.hpp"
#include "../Character/Player.hpp"
#include "../Character/Enemy.hpp"

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&);               \
  void operator=(const TypeName&)
class SceneGameover:public Scene{
	public:
		void print();
		void aNewGame();
	private:
	    static SceneGameover* _instance;
        SceneGameover() {}//¹¹Ôìº¯Êý
        ~SceneGameover() {}
        DISALLOW_COPY_AND_ASSIGN(SceneGameover);
};
#endif
