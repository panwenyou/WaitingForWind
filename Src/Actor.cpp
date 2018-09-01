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
	auto str = String::createWithFormat("Actor%d.png", actor_num);

	if (actor != nullptr && actor->initWithFile(str->getCString()))
	{
		// Create physics body
		auto tp_sprite = Sprite::create();
		tp_sprite->setContentSize(Size(80, 150));
		tp_sprite->setTag(0);
		auto body = PhysicsBody::createEdgeBox(Size(tp_sprite->getContentSize().width,
			tp_sprite->getContentSize().height));
		tp_sprite->setPhysicsBody(body);
		actor->addChild(tp_sprite);
		tp_sprite->setAnchorPoint(Vec2(0.0f, 0.0f));
		tp_sprite->setPosition(Vec2(0, 0));
		
		//actor->setPhysicsBody(body);
		actor->winning_point = Vec2(actor->getPositionX(), actor->getPositionY() + 25);

		actor->autorelease();
	}
	else
	{
		delete actor;
		actor = nullptr;
	}
	return actor;
}

void Actor::setPosition(float x, float y) {
	Sprite::setPosition(x, y);
	winning_point = Vec2(x, y + 25);
}

void Actor::changeWinningPoint(Vec2 anchor) {
	winning_point = anchor;
}

Vec2 Actor::getWinningPoint() {
	return winning_point;
}
