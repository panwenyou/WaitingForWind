#include "MainGameMenu.h"


MainGameMenu::~MainGameMenu(void)
{

}

Menu* MainGameMenu::getGameMenu()
{
	return game_menu;
}

bool MainGameMenu::init()
{
	/* To do 在这里添加你想要添加的代码*/

	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto back_item = MenuItemImage::create("Back.png", 
		"Back.png", 
		"Back.png", 
		CC_CALLBACK_1(MainGameMenu::onBackItem,this));
	auto replay_item = MenuItemImage::create("Replay.png", 
		"Replay.png", 
		"Replay.png", 
		CC_CALLBACK_1(MainGameMenu::onReplayItem,this));
	
	replay_item->setPosition(visibleSize.width-120, visibleSize.height-50);
	back_item->setPosition(visibleSize.width-60, visibleSize.height-50);

	game_menu = Menu::create(replay_item, back_item, NULL);
	game_menu->setPosition(Vec2::ZERO);

	return true;
}

void MainGameMenu::onBackItem(Ref* pSender)
{
	Director::getInstance()->popScene();
}

void MainGameMenu::onReplayItem(Ref* pSender)
{
	auto scene = Director::getInstance()->getRunningScene();
	auto layer = dynamic_cast<BasicScene*>(scene->getChildByTag(0));
	layer->resetHatPosition();
}
