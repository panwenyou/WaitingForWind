#include "PowerItem.h"

PowerItem::PowerItem() {
	power_type = 0;
	item_type = 0;
}

PowerItem::~PowerItem() {

}

PowerItem* PowerItem::create() {
	auto pi = new PowerItem();
	if (pi != nullptr && pi->initWithFile("empty_power.png")) {
		pi->autorelease();
	}
	else {
		delete pi;
		pi = nullptr;
	}
	return pi;
}

bool PowerItem::init() {
	if (!Sprite::init()) {
		return false;
	}
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(PowerItem::onTouchBegan, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	
	return true;
}


bool PowerItem::onTouchBegan(Touch *pTouch, Event *pEvent) {
	return false;
}

void PowerItem::onTouchEnded(Touch *pTouch, Event *pEvent)
{
	//这里写结束触摸需要实现的功能  
	CCLOG("clicked");
}

void PowerItem::setImage(const char* file_path) {
	this->setTexture(file_path);
}

