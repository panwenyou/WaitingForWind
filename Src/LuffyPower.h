#ifndef LUFFYPOWER_H
#define LUFFYPOWER_H

#include "PowerItem.h"

USING_NS_CC;

class LuffyPower :public PowerItem {
public:
	LuffyPower() {}
	~LuffyPower() {}

	static LuffyPower* create();

	virtual bool init();
	void setItemType(int t);

	//¿ªÊ¼´¥Ãþ  
	virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);

	void animation_call_back1();
	void animation_call_back2();
private:
	Vector<SpriteFrame*> frames;
	Vector<SpriteFrame*> frames2;
	int item_type;
};

#endif