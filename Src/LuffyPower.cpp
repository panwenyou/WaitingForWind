#include "LuffyPower.h"

LuffyPower* LuffyPower::create() {
	auto pi = new LuffyPower();
	if (pi != nullptr && pi->init()) {
		pi->autorelease();
	}
	else {
		delete pi;
		pi = nullptr;
	}
	return pi;
}

bool LuffyPower::init() {
	if (!PowerItem::init()) {
		return false;
	}
	item_type = 0;
	this->setImage("luffy_power.png");
	frames.pushBack(SpriteFrame::create("luffy_ani1.png", Rect(0, 0, 80, 300)));
	frames.pushBack(SpriteFrame::create("luffy_ani2.png", Rect(0, 0, 80, 300)));
	frames.pushBack(SpriteFrame::create("luffy_ani3.png", Rect(0, 0, 80, 300)));
	frames.pushBack(SpriteFrame::create("luffy_ani4.png", Rect(0, 0, 80, 300)));
	frames.pushBack(SpriteFrame::create("luffy_ani5.png", Rect(0, 0, 80, 300)));

	frames2.pushBack(SpriteFrame::create("luffy_ani5.png", Rect(0, 0, 80, 300)));
	frames2.pushBack(SpriteFrame::create("luffy_ani4.png", Rect(0, 0, 80, 300)));
	frames2.pushBack(SpriteFrame::create("luffy_ani3.png", Rect(0, 0, 80, 300)));
	frames2.pushBack(SpriteFrame::create("luffy_ani2.png", Rect(0, 0, 80, 300)));
	frames2.pushBack(SpriteFrame::create("luffy_ani1.png", Rect(0, 0, 80, 300)));

	return true;

}

void LuffyPower::setItemType(int t) {
	item_type = t;
}

bool LuffyPower::onTouchBegan(Touch *pTouch, Event *pEvent) {
	auto target = static_cast<PowerItem*>(pEvent->getCurrentTarget());

	Vec2 locationInNode = target->convertToNodeSpace(pTouch->getLocation());
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);

	if (rect.containsPoint(locationInNode))
	{
		if (item_type == 0) {
			this->setImage("luffy_power_picked.png");
			item_type = 1;

			// 获得Actor
			auto parent = Director::getInstance()->getRunningScene()->getChildByTag(0);
			auto cur_actor = dynamic_cast<Actor*>(parent->getChildByTag(1));
			// 取消actor的判定位置
			cur_actor->changeWinningPoint(Vec2(0, 0));
			// 播放动画
			auto animation = Animation::createWithSpriteFrames(frames, 0.1f);
			auto animate = Animate::create(animation);
			auto func = CallFunc::create(CC_CALLBACK_0(LuffyPower::animation_call_back1, this));
			auto sequence = Sequence::create(animate, func, nullptr);
			cur_actor->runAction(sequence);
		}
		else {
			this->setImage("luffy_power.png");
			item_type = 0;
			// 获得Actor
			auto parent = Director::getInstance()->getRunningScene()->getChildByTag(0);
			auto cur_actor = dynamic_cast<Actor*>(parent->getChildByTag(1));

			// 播放动画
			auto animation = Animation::createWithSpriteFrames(frames2, 0.1f);
			auto animate = Animate::create(animation);
			auto func = CallFunc::create(CC_CALLBACK_0(LuffyPower::animation_call_back2, this));
			auto sequence = Sequence::create(func, animate, nullptr);
			cur_actor->runAction(sequence);
		}
	}
	return false;
}

void LuffyPower::animation_call_back1() {
	// 获得Actor
	auto parent = Director::getInstance()->getRunningScene()->getChildByTag(0);
	auto cur_actor = dynamic_cast<Actor*>(parent->getChildByTag(1));
	// 改变physical body 的大小
	auto tp_sprite = dynamic_cast<Sprite*>(cur_actor->getChildByTag(0));
	tp_sprite->setContentSize(Size(80, 250));
	auto body = PhysicsBody::createEdgeBox(Size(tp_sprite->getContentSize().width,
		tp_sprite->getContentSize().height));
	tp_sprite->setPhysicsBody(body);
	// 改变胜利位置
	cur_actor->changeWinningPoint(Vec2(cur_actor->getPositionX(),
		cur_actor->getPositionY() + 135));
}

void LuffyPower::animation_call_back2() {
	// 获得Actor
	auto parent = Director::getInstance()->getRunningScene()->getChildByTag(0);
	auto cur_actor = dynamic_cast<Actor*>(parent->getChildByTag(1));
	// 改变physical body 的大小
	auto tp_sprite = dynamic_cast<Sprite*>(cur_actor->getChildByTag(0));
	tp_sprite->setContentSize(Size(80, 150));
	auto body = PhysicsBody::createEdgeBox(Size(tp_sprite->getContentSize().width,
		tp_sprite->getContentSize().height));
	tp_sprite->setPhysicsBody(body);
	// 改变胜利位置
	cur_actor->changeWinningPoint(Vec2(cur_actor->getPositionX(),
		cur_actor->getPositionY() + 25));
}