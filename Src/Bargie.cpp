#include "Bargie.h"

bool Bargie::init(int t) {
	auto str = String::createWithFormat("bd\\bargie%d_destroy1.png", t);
	if (!this->initWithFile(str->getCString()))
		return false;

	// Create Physical Body
	Size physical_size;
	switch (t) {
	case 1: {physical_size = Size(100, 50); break; }
	case 2: {physical_size = Size(150, 70); break; }
	case 3: {physical_size = Size(50, 60); break; }
	case 4: {physical_size = Size(50, 50); break; }
	case 5: {physical_size = Size(100, 100); break; }
	}
	PhysicsBody* physics_body;
	physics_body = PhysicsBody::createBox(physical_size);
	this->setPhysicsBody(physics_body);
	this->getPhysicsBody()->setGravityEnable(false);

	auto width = this->getContentSize().width;
	auto height = this->getContentSize().height;
	for (int i = 1; i <= 7; i++) {
		str = String::createWithFormat("bd\\bargie%d_destroy%d.png", t, i);
		vec.pushBack(SpriteFrame::create(str->getCString(), Rect(0, 0, width, height)));
	}
	
	return true;
}

void Bargie::destroyAnimation() {
	this->setContentSize(this->vec.at(0)->getOriginalSize());
	this->getPhysicsBody()->setEnabled(false);
	this->setVelocity(0, 0);
	auto animation = Animation::createWithSpriteFrames(this->vec, 0.1);
	auto animate = Animate::create(animation);
	auto smooth = FadeOut::create(1.0);
	auto cb = CallFunc::create(CC_CALLBACK_0(Bargie::removeFromParent, this));
	auto seq = Sequence::create(animate, smooth, cb, nullptr);
	this->runAction(seq);
}

Bargie* Bargie::create(int t) {
	auto bargie = new Bargie();
	if (bargie != nullptr && bargie->init(t)) {
		bargie->autorelease();
	}
	return bargie;
}