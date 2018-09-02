#include "GameScene2.h"


bool GameScene2::init()
{
	if (!BasicScene::init())
	{
		return false;
	}

	auto visible_size = Director::getInstance()->getVisibleSize();

	auto bg = Sprite::create("LuffyStage1BG.png");
	bg->setPosition(visible_size.width/2, visible_size.height/2);
	bg->setLocalZOrder(-2);
	this->addChild(bg);

	auto wood = Barrier::create("Wood.png",1);
	wood->setPosition(visible_size.width - wood->getContentSize().width/2, 500);

	auto luffy = Actor::create(1);
	luffy->setPosition(wood->getPositionX(),
		wood->getPositionY() + wood->getContentSize().height/2 + luffy->getContentSize().height/2);

	auto bagie1 = Bargie::create(1);
	bagie1->setPosition(50,860);
	this->bc.addBarrier(bagie1);

	auto bagie2 = Bargie::create(2);
	bagie2->setPosition(visible_size.width-50,780);
	this->bc.addBarrier(bagie2);

	auto bagie3 = Bargie::create(3);
	bagie3->setPosition(50,560);
	this->bc.addBarrier(bagie3);

	auto bagie4 = Bargie::create(4);
	bagie4->setPosition(visible_size.width-50,360);
	this->bc.addBarrier(bagie4);

	auto bagie5 = Bargie::create(5);
	bagie5->setPosition(50,250);
	this->bc.addBarrier(bagie5);

	bagie1->setVelocity(100, 0);
	bagie2->setVelocity(-100,0);
	bagie3->setVelocity(100,0);
	bagie4->setVelocity(100,0);
	bagie5->setVelocity(-100,0);

	auto fan = Fan::create(Fan::NORTH);
	fan->setPosition(visible_size.width/2, fan->getContentSize().height/2 + 120);
	auto fan2 = Fan::create(Fan::NORTH_EAST);
	fan2->setPosition(100, visible_size.height/2);

	auto hat = Hat::create(1);
	hat->setPosition(visible_size.width/2, fan->getPosition().y + 100);

	myAddChild(fan, BasicScene::TYPE_FAN);
	myAddChild(fan2, BasicScene::TYPE_FAN);
	myAddChild(luffy,BasicScene::TYPE_ACTOR);
	myAddChild(hat, BasicScene::TYPE_HAT);
	myAddChild(bagie1, BasicScene::TYPE_BARRIER);
	myAddChild(bagie2, BasicScene::TYPE_BARRIER);
	myAddChild(bagie3, BasicScene::TYPE_BARRIER);
	myAddChild(bagie4, BasicScene::TYPE_BARRIER);
	myAddChild(bagie5, BasicScene::TYPE_BARRIER);
	myAddChild(wood, BasicScene::TYPE_BARRIER);

	addPower();

	return true;
}

Scene* GameScene2::createScene()
{
	Scene* scene = Scene::createWithPhysics();
	auto layer = GameScene2::create();
	scene->addChild(layer);
	return scene;
}

void GameScene2::resetHatPosition()
{
	auto gs2 = GameScene2::createScene();
	Director::getInstance()->replaceScene(gs2);
}

void GameScene2::addPower() {
	auto power_bar = this->getChildByName("power_bar");
	auto power_layout = power_bar->getChildByName("power_layout");

	auto btn = LuffyPower::create();
	btn->setContentSize(Size(100, 100));
	btn->setPosition(Vec2(100, 60));
	power_layout->addChild(btn);

	auto btn2 = ZoroPower::create();
	btn2->setContentSize(Size(100, 100));
	btn2->setPosition(Vec2(220, 60));
	power_layout->addChild(btn2);

	for (int i = 0; i < 2; i++) {
		auto btn = PowerItem::create();
		btn->setImage("empty_power.png");
		btn->setContentSize(Size(100, 100));
		btn->setPosition(Vec2(340 + i * 120, 60));
		power_layout->addChild(btn);
	}
}