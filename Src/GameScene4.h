#ifndef GAME_SCENE4_H
#define GAME_SCENE4_H

#include "BasicScene.h"
#include "Drama.h"

class GameScene4 : public BasicScene
{
private:
	Vector<Drama*> dramaList;
public:
	virtual bool init();
	virtual void resetHatPosition();
	static Scene* createScene();
	CREATE_FUNC(GameScene4);
};

#endif
