#include "GameScene1.h"


bool GameScene1::init()
{
	if (!BasicScene::init())
	{
		return false;
	}

	auto visible_size = Director::getInstance()->getVisibleSize();

	auto bg = Sprite::create("LuffyStage1BG.png");
	bg->setLocalZOrder(-1);
	auto hat = Hat::create(1);
	auto fan = Fan::create(Fan::NORTH_EAST);
	auto actor = Actor::create(1);


	bg->setPosition(visible_size.width/2, visible_size.height/2);
	fan->setPosition(100, 220);
	hat->setPosition(visible_size.width/2, visible_size.height - 50);
	actor->setPosition(visible_size.width - 80, actor->getContentSize().height);
	

	this->addChild(bg);
	myAddChild(hat, BasicScene::TYPE_HAT);
	myAddChild(fan,BasicScene::TYPE_FAN);
	myAddChild(actor,BasicScene::TYPE_ACTOR);

	addPower();

	return true;
}

void GameScene1::addPower() {
	auto power_bar = this->getChildByName("power_bar");
	auto power_layout = power_bar->getChildByName("power_layout");

	auto btn = PowerItem::create();
	btn->setImage("luffy_power.png");
	btn->setContentSize(Size(100, 100));
	btn->setPosition(Vec2(100, 60));
	power_layout->addChild(btn);

	for (int i = 0; i < 9; i++) {
		btn = PowerItem::create();
		btn->setContentSize(Size(100, 100));
		btn->setPosition(Vec2(220 + i * 120, 60));
		power_layout->addChild(btn);
	}
}

void GameScene1::resetHatPosition()
{
	auto gs1 = GameScene1::createScene();
	Director::getInstance()->replaceScene(gs1);
}

Scene* GameScene1::createScene()
{
	// Create Physical World
	Scene* scene = Scene::createWithPhysics();
	auto layer = GameScene1::create();
	layer->setTag(0);
	scene->addChild(layer);
	return scene;
}

