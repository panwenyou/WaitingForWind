#include "CollisionController.h"

CollisionController::~CollisionController(void)
{
	if (hat != nullptr)
		delete hat;

	if (actor != nullptr)
		delete actor;
}

void CollisionController::addActor(Actor* a)
{
	actor = a;
}

void CollisionController::addHat(Hat* h)
{
	hat = h;
}

/*
	Actor大小：80 * 200
	Hat大小  ：100 * 50
	假设头部约占人身高的1/4（即50像素）
	假设头的上半部分占头的一半（即25像素）
	碰撞成功：帽子的锚点处在头的上半部分
	X_ACTOR - 40 < X_HAT <　X_ACTOR + 40
	Y_ACTOR+ 75 < Y_HAT < Y_ACTOR + 100
	*/
bool CollisionController::isWin()
{
	/* To do 在这里添加你想要添加的代码*/
	Point point_actor = actor->getPosition();
	Point point_hat = hat->getPosition();

	int x_actor = point_actor.x, y_actor = point_actor.y;
	int x_hat = point_hat.x, y_hat = point_hat.y;
	int deltax = x_hat - x_actor;
	int deltay = y_hat - y_actor;

	if (abs(deltax) <= 40 && 
		deltay >= 75 && 
		deltay <= 100) // include math.h in header file
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
