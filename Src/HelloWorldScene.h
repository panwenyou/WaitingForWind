#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "StageChoosingScene.h"
#include "TutorialScene.h"
#include "AboutScene.h"

USING_NS_CC;

class HelloWorld : public Layer
{
public:
	int selected_state;

    
    static cocos2d::Scene* createScene();

    
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(Ref* pSender);

	void onStartCallBack(Ref* pSender);

	void onTutorialCallBack(Ref* pSender);

	void onAboutCallBack(Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
