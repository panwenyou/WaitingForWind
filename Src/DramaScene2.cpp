#include "DramaScene2.h"

Scene* DramaScene2::createScene()
{
	auto scene = Scene::create();
	auto ds = DramaScene2::create();
	scene->addChild(ds);
	return scene;
}

bool DramaScene2::init()
{
	this->scheduleUpdate();

	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto drama1 = Drama::create("Drama2-1.png");
	auto drama2 = Drama::create("Drama2-2.png");
	drama1->setPosition(visibleSize.width/2, visibleSize.height/2);
	drama2->setPosition(visibleSize.width/2, visibleSize.height/2);
	this->addChild(drama2);
	this->addChild(drama1);

	return true;
}

void DramaScene2::update(float dt)
{
	if (this->getChildrenCount() == 0)
	{
		auto gs2 = GameScene2::createScene();
		Director::getInstance()->replaceScene(gs2);
	}
}