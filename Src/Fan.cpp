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
		// 说先设好风扇的方向
		fan->setDirection(direction);
		
		//touch需要添加监视器
		auto listener = EventListenerTouchOneByOne::create();
		
		//允许触摸
		listener->setSwallowTouches(true);

		//触摸的回掉函数
		listener->onTouchBegan = CC_CALLBACK_2(Fan::onTouchBegan, fan);
		listener->onTouchEnded = CC_CALLBACK_2(Fan::onTouchEnded, fan);
		Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, fan);

		// Create PhysicsBody
		// 明确是个有物理属性额物体
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

	// 通过判断点击范围是否在风扇的区域来确定是否点到风扇
	if (rect.containsPoint(locationInNode))
	{
		auto fanPos = this->getPosition();

		// 定义风的8个方向标准单位
		int dir[8][2] = { { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 }, { -1, 0 }, { -1, 1 } };

		// 根据tag来找到帽子
		auto hat = this->getParent()->getChildByTag(0);

		// 帽子的坐标
		auto hatPos = hat->getPosition();

		// 旋转队对应的角度
		// 如果风扇是斜的， 将风扇和帽子旋转到正的
		// 然后判断只用判断矩形的边框即可，
		// 相当于旋转了坐标系， 简化问题的处理
		auto g = hatPos.rotateByAngle(fanPos, 3.14 / 4 * (direction - 1));

		// 只用判断旋转之后的坐标是否在出风处
		if (abs(g.x - fanPos.x) < windWidth / 2 && g.y - fanPos.y < windHeight && g.y > fanPos.y) {
			hat->getPhysicsBody()->setVelocity(Vec2(dir[direction - 1][0] * windSpeed, dir[direction - 1][1] * windSpeed));
		}
	}
	return false;

}

void Fan::onTouchEnded(Touch *pTouch, Event *pEvent)
{
	//这里写结束触摸需要实现的功能  
}
