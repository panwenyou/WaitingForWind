#include "GameScene1.h"


bool GameScene1::init()
{
	if (!BasicScene::init())
	{
		return false;
	}

	auto visible_size = Director::getInstance()->getVisibleSize();

	auto bg = Sprite::create("LuffyStage1BG.png");
	auto hat = Hat::create(1);
	auto fan = Fan::create(Fan::NORTH_EAST);
	auto actor = Actor::create(1);


	bg->setPosition(visible_size.width/2, visible_size.height/2);
	fan->setPosition(100, 100);
	hat->setPosition(visible_size.width/2, visible_size.height - 50);
	actor->setPosition(visible_size.width - 80, actor->getContentSize().height);
	

	this->addChild(bg);
	myAddChild(hat, BasicScene::TYPE_HAT);
	myAddChild(fan,BasicScene::TYPE_FAN);
	myAddChild(actor,BasicScene::TYPE_ACTOR);
	

	return true;
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

