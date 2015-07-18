#include "DramaScene.h"

Scene* DramaScene::createScene()
{
	auto scene = Scene::create();
	auto ds = DramaScene::create();
	scene->addChild(ds);
	return scene;
}

bool DramaScene::init()
{
	this->scheduleUpdate();

	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto drama1 = Drama::create("Drama1-1.png");
	auto drama2 = Drama::create("Drama1-2.png");
	drama1->setPosition(visibleSize.width/2, visibleSize.height/2);
	drama2->setPosition(visibleSize.width/2, visibleSize.height/2);
	this->addChild(drama2);
	this->addChild(drama1);

	return true;
}

void DramaScene::update(float dt)
{
	if (this->getChildrenCount() == 0)
	{
		auto gs1 = GameScene1::createScene();
		Director::getInstance()->replaceScene(gs1);
	}
}