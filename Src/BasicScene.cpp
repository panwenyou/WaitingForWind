#include "BasicScene.h"


bool BasicScene::init()
{
	if(!Layer::init())
	{
		return false;
	}

	// 初始化tag值
	max_barrier_tag = 20;
	max_fan_tag = 10;

	// 初始化is_win
	is_win = false;


	// 调用计时器
	this->scheduleUpdate();

	this->schedule(schedule_selector(BasicScene::natrualWindComes), 5.0f);

	/* To do 在这里添加你想要添加的代码*/
	auto visible_size = Director::getInstance()->getVisibleSize();

	// 给环境加上物理边界
	auto world_edge = PhysicsBody::createEdgeBox(Size(visible_size.width, visible_size.height-120));
	auto world = Node::create();
	world->setPhysicsBody(world_edge);
	world->setPosition(visible_size.width/2, visible_size.height/2 + 60);
	this->addChild(world);
	
	// 设置按钮
	// 包括回退按钮和
	auto back_item = MenuItemImage::create("Back.png", 
		"Back_clicked.png", 
		"Back.png", 
		CC_CALLBACK_1(BasicScene::onBackCallBack,this));
	auto replay_item = MenuItemImage::create("Replay.png", 
		"Replay_clicked.png", 
		"Replay.png", 
		CC_CALLBACK_1(BasicScene::onReplayCallBack, this));
	replay_item->setPosition(visible_size.width-110, visible_size.height-50);
	back_item->setPosition(visible_size.width-40, visible_size.height-50);

	auto menu = Menu::create(replay_item, back_item, NULL);
	menu->setPosition(Vec2::ZERO);

	this->addChild(menu,1);

	addPowerList();

	return true;
}

void BasicScene::addPowerList() {
	auto visible_size = Director::getInstance()->getVisibleSize();
	auto power_bar = ListView::create();
	power_bar->setDirection(ui::ScrollView::Direction::HORIZONTAL);
	power_bar->setBounceEnabled(true);
	power_bar->setBackGroundImage("magic_bg.png");
	power_bar->setAnchorPoint(Vec2(0.5f, 0.5f));
	power_bar->setContentSize(Size(640, 120));
	power_bar->setPosition(Vec2(visible_size.width / 2, 60));
	power_bar->setName("power_bar");

	auto power_layout = Layout::create();
	power_layout->setName("power_layout");
	power_layout->setContentSize(power_bar->getContentSize());
	power_bar->addChild(power_layout);

	this->addChild(power_bar);
}

void BasicScene::update(float dt)
{
	adjustPerFrame();
}

void BasicScene::adjustPerFrame()
{
	// 判断是否已通过关卡
	if (!is_win)
	{
		if (cc.isWin())
		{
			onWinning();
			is_win = true;
		}
	}
}

void BasicScene::onWinning()
{
	/* To do 在这里添加你想要添加的代码*/
	auto hat = dynamic_cast<Hat*> (this->getChildByTag(0));
	int hat_num = hat->hat_num;
	hat->removeItself();

	auto actor = this->getChildByTag(1);
	hat = Hat::create(hat_num);
	hat->setPosition(actor->getPositionX(), actor->getPositionY()+75);
	hat->comeOut();
	this->addChild(hat);

	auto winning_layer = WinningLayer::create();

	// Set initial size
	winning_layer->setScale(0.1,0.1);

	// Scale up action
	auto scale = ScaleTo::create(0.5f,1,1); 

	winning_layer->runAction(scale);

	this->getParent()->addChild(winning_layer);
	
}

void BasicScene::natrualWindComes(float dt)
{

	/* To do 在这里添加你想要添加的代码*/
	if (!is_win)
	{
		auto visible_size = Director::getInstance()->getVisibleSize();

		auto hat = getChildByTag(0);

		// Actions to perform
		auto velocity = hat->getPhysicsBody()->getVelocity();
		velocity.y = 200;
		hat->getPhysicsBody()->setVelocity(velocity);
	}
}

void BasicScene::myAddChild(Sprite* s, const int type)
{
	if (s == nullptr)
		return;

	// 根据类型将指针添加到CollisionController中
	if (type == TYPE_ACTOR)
	{
		Actor* ac = static_cast<Actor*> (s);
		ac->setTag(1);
		cc.addActor(ac);
	}
	else if (type == TYPE_HAT)
	{
		Hat* h = static_cast<Hat*> (s);
		h->setTag(0);
		cc.addHat(h);
	}
	else if (type == TYPE_FAN)
	{
		Fan* fan = dynamic_cast<Fan*> (s);
		fan->setTag(max_fan_tag++);
	}

	// 将实例添加到Layer中
	this->addChild(s);
}

void BasicScene::onBackCallBack(Ref* pSender)
{
	auto director = Director::getInstance();
	director->getRunningScene()->cleanup();
	director->popScene();
}

void BasicScene::onReplayCallBack(Ref* pSender)
{
	this->resetHatPosition();
}

BasicScene::~BasicScene()
{
	cc.clean();
}