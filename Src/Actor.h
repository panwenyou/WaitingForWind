/* Waiting For Wind

   ͳһ��������
   1.��������ĸ��д
   2.��������������������ĸСд����������ÿ��������������ĸ��д���磺 addChild(), runAction()�ȵ�
   3.������ȫСд�����ʼ����»��߷ָ�磺x_position, y_position�ȵȡ�*/

#ifndef ACTOR_H
#define ACTOR_H

#include "cocos2d.h"

USING_NS_CC;

class Actor : public Sprite
{
public:
	Actor(void);
	~Actor(void);

	// �ı�ʤ������
	void changeWinningPoint(Vec2 anchor);
	void setPosition(float x, float y);
	Vec2 getWinningPoint();

	static Actor* create(int actor_num);

private:
	Vec2 winning_point;
};

#endif

