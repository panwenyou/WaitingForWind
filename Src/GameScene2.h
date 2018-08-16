#ifndef GAME_SCENE2_H
#define GAME_SCENE2_H

#include "BasicScene.h"

class GameScene2 : public BasicScene
{
public:
	virtual bool init();
	static Scene* createScene();
	void resetHatPosition();
	CREATE_FUNC(GameScene2);
};

#endif

