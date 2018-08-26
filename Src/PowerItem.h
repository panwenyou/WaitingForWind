#ifndef POWER_ITEM_H
#define POWER_ITEM_H

#include "cocos2d.h"

USING_NS_CC;

class PowerItem :public Sprite
{
public:
	PowerItem();
	~PowerItem();

	static PowerItem* create();

	void setImage(const char* file_path);

	//¿ªÊ¼´¥Ãþ  
	virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
};

# endif