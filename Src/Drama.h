#ifndef DRAMA_H
#define DRAMA_H

#include "cocos2d.h"

USING_NS_CC;

class Drama : public Sprite
{
public:
	static Drama* create(char* filename);

	virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
	virtual void onTouchMoved(Touch *pTouch, Event *pEvent);
	virtual void onTouchEnded(Touch *pTouch, Event *pEvent);

	void ActionEnded();

private:
	bool is_touch;
	Vec2 origin_pos;
};

#endif