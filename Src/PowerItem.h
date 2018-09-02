#ifndef POWER_ITEM_H
#define POWER_ITEM_H

#include "cocos2d.h"
#include "Actor.h"
#include "BasicScene.h"

USING_NS_CC;

class PowerItem :public Sprite
{
public:
	PowerItem();
	~PowerItem();

	static PowerItem* create();

	virtual bool init();

	void setImage(const char* file_path);

	//¿ªÊ¼´¥Ãþ  
	virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
	//´¥Ãþ½áÊø  
	virtual void onTouchEnded(Touch *pTouch, Event *pEvent);

private:
	int power_type;
	int item_type;
};

# endif