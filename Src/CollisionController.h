/* Waiting For Wind

   ͳһ��������
   1.��������ĸ��д
   2.��������������������ĸСд����������ÿ��������������ĸ��д���磺 addChild(), runAction()�ȵ�
   3.������ȫСд�����ʼ����»��߷ָ�磺x_position, y_position�ȵȡ�

   CollisionController�������ʦ��֪:
   1.��ò�Ҫ�Ķ��Ѷ���ķ���������,��Ҫ�Ķ������֪
   2.����ĺ����ɳ������ʦ�Լ����塣
   */

#ifndef COLLISION_CONTROLLER_H
#define COLLISION_CONTROLLER_H

#include "Actor.h"
#include "Barrier.h"
#include "Hat.h"
#include "Fan.h"
#include <math.h>//�Լ�

struct Area {
public:
	Vec2 left_top;
	Vec2 botton_down;
	Area() {
		left_top = Vec2(0.0f, 0.0f);
		botton_down = Vec2(0.0f, 0.0f);
	}
};

class CollisionController
{
public:
	CollisionController(void) : hat(nullptr), actor(nullptr) {}
	~CollisionController(void);
	
	// ���Hatʵ��ָ��
	void addHat(Hat* h);

	// ���Hatʵ��ָ��
	void addActor(Actor* ac);

	// ����Ƿ�ﵽʤ������
	bool isWin();

	void clean();


private:
	Hat* hat;
	Actor* actor;
};

#endif

