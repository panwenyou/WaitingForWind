/* Waiting For Wind

   ͳһ��������
   1.��������ĸ��д
   2.��������������������ĸСд����������ÿ��������������ĸ��д���磺 addChild(), runAction()�ȵ�
   3.������ȫСд�����ʼ����»��߷ָ�磺x_position, y_position�ȵȡ�*/

#ifndef BARRIER_H
#define BARRIER_H

#include "cocos2d.h"

USING_NS_CC;

class Barrier : public Sprite
{
public:
	Barrier(void);
	~Barrier(void);

	// ��ײ���
	virtual void hit() {};
	// ���ٶ���
	virtual void destroyAnimation() {};
	// �˶��ı�
	virtual void changeAction() {};

	static Barrier* create(char* filename, int type);
	void setVelocity(int x, int y);
};

#endif

