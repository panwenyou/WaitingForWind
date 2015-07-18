#ifndef DRAMASCENE2_H
#define DRAMASCENE2_H

#include "cocos2d.h"
#include "Drama.h"
#include "GameScene2.h"

USING_NS_CC;

class DramaScene2 : public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	void update(float dt);
	CREATE_FUNC(DramaScene2);
};

#endif