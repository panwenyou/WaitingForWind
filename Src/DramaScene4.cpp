#include "DramaScene4.h"

Scene* DramaScene4::createScene()
{
	auto scene = Scene::create();
	auto ds = DramaScene4::create();
	scene->addChild(ds);
	return scene;
}

bool DramaScene4::init()
{
	this->scheduleUpdate();

	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto drama1 = Drama::create("Drama3-1.png");
	auto drama2 = Drama::create("Drama3-2.png");
	auto drama3 = Drama::create("Drama3-3.png");
	drama1->setPosition(visibleSize.width/2, visibleSize.height/2);
	drama2->setPosition(visibleSize.width/2, visibleSize.height/2);
	drama3->setPosition(visibleSize.width/2, visibleSize.height/2);
	this->addChild(drama3);
	this->addChild(drama2);
	this->addChild(drama1);

	return true;
}

void DramaScene4::update(float dt)
{
	if (this->getChildrenCount() == 0)
	{
		auto gs4 = GameScene4::createScene();
		Director::getInstance()->replaceScene(gs4);
	}
}