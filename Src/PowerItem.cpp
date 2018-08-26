#include "PowerItem.h"

PowerItem::PowerItem() {

}

PowerItem::~PowerItem() {

}

PowerItem* PowerItem::create() {
	auto pi = new PowerItem();
	if (pi != nullptr && pi->initWithFile("empty_power.png")) {
		auto listener = EventListenerTouchOneByOne::create();
		listener->setSwallowTouches(true);
		listener->onTouchBegan = CC_CALLBACK_2(PowerItem::onTouchBegan, pi);
		Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, pi);
		pi->autorelease();
	}
	else {
		delete pi;
		pi = nullptr;
	}
	return pi;
}

bool PowerItem::onTouchBegan(Touch *pTouch, Event *pEvent) {
	CCLOG("POWER ITEM CLICKED");
	return false;
}

void PowerItem::setImage(const char* file_path) {
	this->setTexture(file_path);
}

