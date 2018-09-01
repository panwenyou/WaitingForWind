#ifndef ZOROPOWER_H
#define ZOROPOWER_H

#include "PowerItem.h"

class ZoroPower : public PowerItem {
public:
	ZoroPower() {}
	~ZoroPower() {}

	static ZoroPower* create();

	virtual bool init();
	
	//开始触摸  
	virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);

	//冷却动画回调
	void animationCallBack();
	//过场动画回调
	void animationcallBack2();
private:
	bool available;
};

#endif