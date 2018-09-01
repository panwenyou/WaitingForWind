#include "CollisionController.h"

CollisionController::~CollisionController(void)
{	
	
}

void CollisionController::addHat(Hat* h)
{
	hat = h;
}

void CollisionController::addActor(Actor* ac)
{
	actor = ac;
}

/*
	Actor��С��80 * 200
	Hat��С  ��100 * 50
	����ͷ��Լռ����ߵ�1/4����50���أ�
	����ͷ���ϰ벿��ռͷ��һ�루��25���أ�
	��ײ�ɹ���ñ�ӵ�ê�㴦��ͷ���ϰ벿��
	X_ACTOR - 40 < X_HAT <��X_ACTOR + 40
	Y_ACTOR+ 75 < Y_HAT < Y_ACTOR + 100
	*/
bool CollisionController::isWin()
{
	/* To do �������������Ҫ��ӵĴ���*/
	Point point_actor = actor->getWinningPoint();
	Point point_hat = hat->getPosition();

	int x_actor = point_actor.x, y_actor = point_actor.y;
	int x_hat = point_hat.x, y_hat = point_hat.y;
	int deltax = x_hat - x_actor;
	int deltay = y_hat - y_actor;

	if (abs(deltax) <= 40 && 
		abs(deltay) <= 25) // include math.h in header file
	{
		//hat->stopAllActions(); // should like that?
		hat->getPhysicsBody()->setGravityEnable(false);
		hat->getPhysicsBody()->setVelocity(ccp(0,0));
		return true;
	}
	return false;
}

void CollisionController::clean()
{
	hat = nullptr;
	actor = nullptr;
}
