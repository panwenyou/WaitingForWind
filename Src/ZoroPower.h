#ifndef ZOROPOWER_H
#define ZOROPOWER_H

#include "PowerItem.h"

class ZoroPower : public PowerItem {
public:
	ZoroPower() {}
	~ZoroPower() {}

	static ZoroPower* create();

	virtual bool init();
	
	//��ʼ����  
	virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);

	//��ȴ�����ص�
	void animationCallBack();
	//���������ص�
	void animationcallBack2();
	//Ч���ص�
	void animationcallBack3();
private:
	bool available;
};

#endif