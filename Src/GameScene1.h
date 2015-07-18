#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "BasicScene.h"
#include "Drama.h"

class GameScene1 : public BasicScene
{
private:
	Vector<Drama*> dramaList;
public:
	virtual bool init();
	virtual void resetHatPosition();
	static Scene* createScene();
	CREATE_FUNC(GameScene1);
};

#endif
