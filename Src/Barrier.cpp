#include "Barrier.h"


Barrier::Barrier(void)
{
}


Barrier::~Barrier(void)
{
}

Barrier* Barrier::create(char* filename, int type)
// Overrite create fucntion of sprite
{
	auto barrier = new Barrier();


	if (barrier != nullptr && barrier->initWithFile(filename))
	{
		// Create Physical Body
		PhysicsBody* physics_body;
		if (type == 0)
			physics_body = PhysicsBody::createBox(barrier->getContentSize());
		else
			physics_body = PhysicsBody::createEdgeBox(barrier->getContentSize());
		barrier->setPhysicsBody(physics_body);
		barrier->getPhysicsBody()->setGravityEnable(false);

		barrier->autorelease();
	}
	else
	{
		delete barrier;
		barrier = nullptr;
	}
	return barrier;
}

void Barrier::setVelocity(int x, int y)
{
	auto v = this->getPhysicsBody()->getVelocity();
	v.x = x;
	v.y = y;
	this->getPhysicsBody()->setVelocity(v);
}
