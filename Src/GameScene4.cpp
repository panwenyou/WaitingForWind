#include "GameScene4.h"


bool GameScene4::init()
{
	if (!BasicScene::init())
	{
		return false;
	}

	auto visible_size = Director::getInstance()->getVisibleSize();

	auto bg = Sprite::create("WindComesStageBG1.png");
	auto hat = Hat::create(2);
	auto fan = Fan::create(Fan::NORTH);
	auto fan2 = Fan::create(Fan::SOUTH_EAST);
	auto actor = Actor::create(2);
	auto cloud = Barrier::create("Cloud.png", 1);


	bg->setPosition(visible_size.width/2, visible_size.height/2);
	fan->setPosition(300, 207);
	fan2->setPosition(250, 700);
	hat->setPosition(300, 237);
	actor->setPosition(541, 345);
	cloud->setPosition(141, 800);
	

	this->addChild(bg);
	myAddChild(hat, BasicScene::TYPE_HAT);
	myAddChild(fan,BasicScene::TYPE_FAN);
	myAddChild(fan2, BasicScene::TYPE_FAN);
	myAddChild(actor,BasicScene::TYPE_ACTOR);
	myAddChild(cloud, BasicScene::TYPE_BARRIER);
	

	return true;
}

void GameScene4::resetHatPosition()
{
	auto gs4 = GameScene4::createScene();
	Director::getInstance()->replaceScene(gs4);
}

Scene* GameScene4::createScene()
{
	// Create Physical World
	Scene* scene = Scene::createWithPhysics();
	auto layer = GameScene4::create();
	layer->setTag(0);
	scene->addChild(layer);
	return scene;
}

