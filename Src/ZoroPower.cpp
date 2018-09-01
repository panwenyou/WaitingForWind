#include "ZoroPower.h"

ZoroPower* ZoroPower::create() {
	auto zoro_power = new ZoroPower();
	if (zoro_power != nullptr && zoro_power->init()) {
		zoro_power->autorelease();
	}
	else {
		delete zoro_power;
		zoro_power = nullptr;
	}
	return zoro_power;
}

bool ZoroPower::init() {
	if (!PowerItem::init()) {
		return false;
	}
	this->available = true;
	this->setImage("zoro_power.png");
	return true;
}

bool ZoroPower::onTouchBegan(Touch *pTouch, Event *pEvent) {
	if (!this->available)
		return false;

	auto target = static_cast<PowerItem*>(pEvent->getCurrentTarget());

	Vec2 locationInNode = target->convertToNodeSpace(pTouch->getLocation());
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);
	if (rect.containsPoint(locationInNode)) {
		auto progress = ProgressTo::create(10, 100);
		auto timer = ProgressTimer::create(Sprite::create("power_cd.png"));
		timer->setType(ProgressTimer::Type::RADIAL);
		timer->setReverseProgress(true);
		timer->setPosition(this->getContentSize().width / 2, this->getContentSize().height / 2);
		timer->setTag(0);
		auto func = CallFunc::create(CC_CALLBACK_0(ZoroPower::animationCallBack, this));
		auto rev = ReverseTime::create(progress);
		auto seq = Sequence::create(rev, func, nullptr);
		timer->runAction(seq);
		this->addChild(timer);

		auto cur_layer = Director::getInstance()->getRunningScene()->getChildByTag(0);
		auto ani_bg = Sprite::create("zoro_power_bg.png");
		ani_bg->setName("power_bg");
		ani_bg->setLocalZOrder(-1);
		ani_bg->setPosition(-320, cur_layer->getContentSize().height / 2);
		auto move_to1 = MoveTo::create(0.3,
			Vec2(cur_layer->getContentSize().width / 2, cur_layer->getContentSize().height / 2));
		auto move_to2 = MoveTo::create(1.0,
			Vec2(cur_layer->getContentSize().width / 2, cur_layer->getContentSize().height / 2));
		auto move_to3 = MoveTo::create(0.3,
			Vec2(cur_layer->getContentSize().width + 320, cur_layer->getContentSize().height / 2));
		auto func2 = CallFunc::create(CC_CALLBACK_0(ZoroPower::animationcallBack2, this));
		auto seq2 = Sequence::create(move_to1, move_to2, move_to3, func2, nullptr);
		ani_bg->runAction(seq2);
		cur_layer->addChild(ani_bg);

		this->available = false;

	}
	return false;
}

void ZoroPower::animationCallBack() {
	this->removeChildByTag(0);
	this->available = true;
}

void ZoroPower::animationcallBack2() {
	auto cur_layer = Director::getInstance()->getRunningScene()->getChildByTag(0);
	cur_layer->removeChildByName("power_bg");
}