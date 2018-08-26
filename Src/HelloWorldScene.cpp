#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));


    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

	auto bg = Sprite::create("BeginBG.png");
	bg->setPosition(visibleSize.width/2, visibleSize.height/2);
	this->addChild(bg);

	auto start = MenuItemImage::create("Start.png", 
		"Start.png", 
		"Start.png", 
		CC_CALLBACK_1(HelloWorld::onStartCallBack, this));
	start->setPosition(100, 260);

	auto tutorial = MenuItemImage::create("Tutorial.png",
		"Tutorial.png", 
		"Tutorial.png",
		CC_CALLBACK_1(HelloWorld::onTutorialCallBack, this));
	tutorial->setPosition(100, 260-start->getContentSize().height);

	auto about = MenuItemImage::create("About.png", 
		"About.png", 
		"About.png",
		CC_CALLBACK_1(HelloWorld::onAboutCallBack, this));
	about->setPosition(100, 260-start->getContentSize().height-tutorial->getContentSize().height);
    
    
	Menu* menu = Menu::create(closeItem, start, tutorial, about, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);

    return true;
}

void HelloWorld::onStartCallBack(Ref* pSender)
{
	Scene* startScene = StageChoosingScene::createScene();
	Director::getInstance()->pushScene(startScene);
}

void HelloWorld::onTutorialCallBack(Ref* pSender)
{
	Scene* ts = TutorialScene::createScene();
	Director::getInstance()->pushScene(ts);
}

void HelloWorld::onAboutCallBack(Ref* pSender)
{
	Scene* about_Scene = AboutScene::createScene();
	Director::getInstance()->pushScene(about_Scene);
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
