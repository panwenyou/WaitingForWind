#include "Actor.h"


Actor::Actor(void)
{
}


Actor::~Actor(void)
{
}

Actor* Actor::create(int actor_num)
{
	auto actor = new Actor();

	//不同的Actor有不同的背景
	auto str = String::createWithFormat("Actor%d.png", actor_num);

	if (actor != nullptr && actor->initWithFile(str->getCString()))
	{
		// Create physics body
		// 使用框架自带的物理引擎来帮助快速开发
		auto body = PhysicsBody::createEdgeBox(Size(actor->getContentSize().width,
			actor->getContentSize().height-50));
		
		actor->setPhysicsBody(body);

		actor->autorelease();
	}
	else
	{
		delete actor;
		actor = nullptr;
	}
	return actor;
}
