/* Waiting For Wind

   ͳһ�������
   1.��������ĸ��д
   2.��������������ĸСд���������ÿ������������ĸ��д���磺 addChild(), runAction()�ȵ�
   3.�����ȫСд�����ʼ����»��߷ָ�磺x_position, y_position�ȵȡ�*/

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