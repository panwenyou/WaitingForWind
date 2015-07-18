#ifndef DRAMASCENE_H
#define DRAMASCENE_H

#include "cocos2d.h"
#include "Drama.h"
#include "GameScene1.h"

USING_NS_CC;

class DramaScene : public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	void update(float dt);
	CREATE_FUNC(DramaScene);
};

#endif