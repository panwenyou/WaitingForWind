#ifndef ABOUT_SCENE_H
#define ABOUT_SCENE_H

#include "cocos2d.h"

USING_NS_CC;

class AboutScene : public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	
	void onBack(Ref* pSender);

	CREATE_FUNC(AboutScene);
};

#endif