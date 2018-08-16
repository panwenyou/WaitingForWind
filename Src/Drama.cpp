#include "Drama.h"

Drama* Drama::create(char* filename)
{
	Drama* d = new Drama();
	if (d != nullptr && d->initWithFile(filename))
	{
		auto edp = Director::getInstance()->getEventDispatcher();
		auto listener = EventListenerTouchOneByOne::create();

		listener->setSwallowTouches(true);
		listener->onTouchBegan = CC_CALLBACK_2(Drama::onTouchBegan, d);
		listener->onTouchEnded = CC_CALLBACK_2(Drama::onTouchEnded, d);
		listener->onTouchMoved = CC_CALLBACK_2(Drama::onTouchMoved, d);
		edp->addEventListenerWithSceneGraphPriority(listener, d);

		d->autorelease();
	}
	d->is_touch = false;
	return d;
}

bool Drama::onTouchBegan(Touch* pTouch, Event* pEvent)
{
	is_touch = true;
	origin_pos = pTouch->getLocation();
	return true;
}

void Drama::onTouchEnded(Touch* pTouch, Event* pEvent)
{
	is_touch = false;
}

void Drama::onTouchMoved(Touch* pTouch, Event* pEvent)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 pos = pTouch->getLocation();

	if (is_touch)
	{
		MoveBy* move;
		if (pos.x < origin_pos.x)
		{
			move = MoveBy::create(1, ccp(-visibleSize.width, 0));
		}
		else
		{
			move = MoveBy::create(1, ccp(visibleSize.width, 0));
		}
		auto ended = CallFunc::create(this, callfunc_selector(Drama::ActionEnded));
		auto sequence = Sequence::create(move, ended, NULL);
		this->runAction(sequence);
	}
}

void Drama::ActionEnded()
{
	this->removeFromParent();
}