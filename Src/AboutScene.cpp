#include "AboutScene.h"

USING_NS_CC;

Scene* AboutScene::createScene()
{
	 // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = AboutScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool AboutScene::init()
{
	if (!Layer::init())
	{
		return false;
	}


	// Get size
	Size visibleSize = Director::getInstance()->getVisibleSize();

	// Background
	auto bg = Sprite::create("AboutBG.png");
	bg->setPosition(visibleSize.width/2, visibleSize.height/2);

	// Back menu item
	auto back_item = MenuItemFont::create("Back", CC_CALLBACK_1(AboutScene::onBack, this));
	back_item->setPosition(580,50);

	// Insert menu item into menu

	auto menu = Menu::create(back_item, NULL);
	menu->setPosition(Vec2::ZERO);

	this->addChild(bg);
	this->addChild(menu);

	return true;
}

void AboutScene::onBack(Ref* pSender)
{
	Director::getInstance()->popScene();
}