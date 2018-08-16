#include "Fan.h"

Fan::Fan(void)
{
}


Fan::~Fan(void)
{
}

Fan* Fan::create(const int direction)
{
	/* To do 在这里添加你想要添加的代码*/
	auto fan = new Fan();

	auto str = String::createWithFormat("Fan.png", direction);

	if (fan != nullptr && fan->initWithFile(str->getCString()))
	{
		fan->setDirection(direction);
		auto listener = EventListenerTouchOneByOne::create();
		listener->setSwallowTouches(true);
		listener->onTouchBegan = CC_CALLBACK_2(Fan::onTouchBegan, fan);
		listener->onTouchEnded = CC_CALLBACK_2(Fan::onTouchEnded, fan);
		Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, fan);

		// Create PhysicsBody
		auto body = PhysicsBody::createEdgeBox(fan->getContentSize());
		fan->setPhysicsBody(body);

		// Rotate fan
		fan->setRotation((direction-1)*45);

		fan->autorelease();

	}
	else
	{
		delete fan;
		fan = nullptr;
	}
	return fan;
}



void Fan::setDirection(int d)
{

	direction = d;
}

bool Fan::onTouchBegan(Touch *pTouch, Event *pEvent)  {

	auto target = static_cast<Sprite*>(pEvent->getCurrentTarget());
	
	Vec2 locationInNode = target->convertToNodeSpace(pTouch->getLocation());
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);

	int windWidth = this->getContentSize().width;
	int windHeight = 600;
	int windSpeed = 100;
	if (rect.containsPoint(locationInNode))
	{
		auto fanPos = this->getPosition();
		int dir[8][2] = { { 0, 1 }, 
		{ 1, 1 }, 
		{ 1, 0 }, 
		{ 1, -1 }, 
		{ 0, -1 }, 
		{ -1, -1 }, 
		{ -1, 0 }, 
		{ -1, 1 } };

		auto hat = this->getParent()->getChildByTag(0);
		if (hat == nullptr)
			return false;
		auto hatPos = hat->getPosition();

		auto g = hatPos.rotateByAngle(fanPos, 3.14 / 4 * (direction - 1));

		if (abs(g.x - fanPos.x) < windWidth / 2 && 
			g.y - fanPos.y < windHeight && 
			g.y > fanPos.y) 
		{
			hat->getPhysicsBody()->setVelocity(Vec2(dir[direction - 1][0] * windSpeed, 
				dir[direction - 1][1] * windSpeed));
		}
	}
	return false;

}

void Fan::onTouchEnded(Touch *pTouch, Event *pEvent)
{
	//这里写结束触摸需要实现的功能  
}
