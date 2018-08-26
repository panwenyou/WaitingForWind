#include "TutorialScene.h"


Scene* TutorialScene::createScene()
{
	auto layer = TutorialScene::create();

	Scene* scene = Scene::createWithPhysics();
	layer->setTag(0);

	scene->addChild(layer);

	return scene;
}

bool TutorialScene::init()
{
	/* To do 在这里添加你想要添加的代码*/
	if (!BasicScene::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	// Initial objects
	auto bg = Sprite::create("TutorialBG.png");
	auto fan = Fan::create(Fan::NORTH);
	auto hat = Hat::create(1);
	auto actor = Actor::create(1);

	// Set objects positions
	bg->setPosition(visibleSize.width/2, visibleSize.height/2);
	fan->setPosition(100,600);
	hat->setPosition(100, 700);
	actor->setPosition(100, 100);

	// add them into 
	this->addChild(bg);
	myAddChild(fan, BasicScene::TYPE_FAN);
	myAddChild(hat, BasicScene::TYPE_HAT);
	myAddChild(actor, BasicScene::TYPE_ACTOR);

	return true;
}

void TutorialScene::resetHatPosition()
{
	auto ts = TutorialScene::createScene();
	Director::getInstance()->replaceScene(ts);
}