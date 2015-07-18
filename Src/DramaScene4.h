#ifndef DRAMASCENE4_H
#define DRAMASCENE4_H

#include "cocos2d.h"
#include "Drama.h"
#include "GameScene4.h"

USING_NS_CC;

class DramaScene4 : public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	void update(float dt);
	CREATE_FUNC(DramaScene4);
};

#endif