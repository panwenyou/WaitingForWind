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

	auto bagie1 = Barrier::create("Bagie1.png",0);
	bagie1->setPosition(50,860);

	auto bagie2 = Barrier::create("Bagie2.png",0);
	bagie2->setPosition(visible_size.width-50,780);

	auto bagie3 = Barrier::create("Bagie3.png",0);
	bagie3->setPosition(50,560);

	auto bagie4 = Barrier::create("Bagie4.png",0);
	bagie4->setPosition(visible_size.width-50,360);

	auto bagie5 = Barrier::create("Bagie5.png",0);
	bagie5->setPosition(50,250);

	/*auto left = MoveBy::create(5, ccp(-visible_size.width+100, 0));
	auto right = MoveBy::create(5, ccp(visible_size.width-100, 0));
	auto sequence1 = Sequence::create(left, right, NULL);
	auto sequence2 = Sequence::create(right, left, NULL);
	auto repeat1 = RepeatForever::create(sequence1);
	auto repeat2 = RepeatForever::create(sequence2);

	bagie1->runAction(repeat2);
	bagie2->runAction(repeat1);
	bagie3->runAction(repeat2);
	bagie4->runAction(repeat1);
	bagie5->runAction(repeat2);*/

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