#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "BasicScene.h"
#include "Drama.h"
#include "PowerItem.h"
#include "LuffyPower.h"


class GameScene1 : public BasicScene
{
private:
	Vector<Drama*> dramaList;
public:
	virtual bool init();
	virtual void resetHatPosition();
	void addPower();
	void btnTouch(Ref *pSender, TouchEventType type);
	static Scene* createScene();
	CREATE_FUNC(GameScene1);
};

#endif
