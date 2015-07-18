#include "Hat.h"


Hat::Hat(void)
{
}


Hat::~Hat(void)
{
}

Hat* Hat::create(int hat_num)
{
	auto hat = new Hat();

	auto str = String::createWithFormat("Hat%d.png", hat_num);
	
	hat->hat_num = hat_num;

	if (hat != nullptr && hat->initWithFile(str->getCString()))
	{
		// Create Physical Body
		auto body = PhysicsBody::createBox(hat->getContentSize());
		hat->setPhysicsBody(body);

		hat->autorelease();
	}
	else
	{
		delete hat;
		hat = nullptr;
	}
	
	return hat;
}

void Hat::setVelocity(Vec2 velocity)
{
	this->getPhysicsBody()->setVelocity(velocity);
}

void Hat::onRemove()
{
	this->removeFromParent();
}

void Hat::removeItself()
{
	auto scale = ScaleTo::create(0.5, 0.1, 0.1);
	auto callfunc = CallFunc::create(CC_CALLBACK_0(Hat::onRemove, this));
	auto sequence = Sequence::create(scale, callfunc, NULL);
	this->runAction(sequence);
}

void Hat::comeOut()
{
	this->setScale(0.1);
	auto scale = ScaleTo::create(0.5, 1, 1);
	this->runAction(scale);
}