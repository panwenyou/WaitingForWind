#include "WinningLayer.h"

bool WinningLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	// Create three sprite
	auto board = Sprite::create("WinBoard.png");
	
	auto visible_size = Director::sharedDirector()->getVisibleSize();


	// Create Back Menu to click
	auto back_item = MenuItemFont::create("OK",CC_CALLBACK_1(WinningLayer::onOkCallBack, this));

	auto menu = Menu::create(back_item, NULL);


	// Set the positions of all of them
	board->setPosition(visible_size.width/2, visible_size.height/2);
	back_item->setPosition(visible_size.width/2, 
		(visible_size.height-board->getContentSize().height)/2);
	menu->setPosition(Vec2::ZERO);

	// Add these to layer
	this->addChild(board);
	this->addChild(menu);

	return true;
}

void WinningLayer::onOkCallBack(Ref* pSender)
{
	auto director = Director::getInstance();
	director->popScene();
}