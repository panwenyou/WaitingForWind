/* Waiting For Wind  @ Team WDLang

   统一命名规则：
   1.类名首字母大写
   2.方法名（函数名）首字母小写，接下来的每个独立单词首字母大写，如： addChild(), runAction()等等
   3.变量名全小写，单词间用下划线分割，如：x_position, y_position等等。
   
   BasicScene程序设计师须知：
   1.所有的游戏主画面都要继承此类，并在子类的init函数中先调用本类的init函数。
   2.此类使用已经实现好了的MainGameMenu以及CollisionController来控制游戏逻辑。
   3.tag值分配。0-Hat, 1-Actor 10~19-Fan 20~100-barrier
   */

#ifndef BASIC_SCENE_H
#define BASIC_SCENE_H

#include "cocos2d.h"
#include "CollisionController.h"
#include "MainGameMenu.h"
#include "Actor.h"
#include "Hat.h"
#include "Leaves.h"
#include "Fan.h"
#include "Barrier.h"
#include "WinningLayer.h"
#include "ui/CocosGUI.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

class BasicScene : public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(BasicScene);

public:
	// 胜利时调用的函数，播放胜利动画并返回选关场景
	void onWinning();

	// 每一帧的回调
	void update(float dt);
	void adjustPerFrame();

	// 每5秒的自然风
	void natrualWindComes(float dt);

	// 添加子节点
	void myAddChild(Sprite* s, const int type);

	// 添加下方技能栏
	void addPowerList();

	// 返回按钮回调
	void onBackCallBack(Ref* pSender);
	void onReplayCallBack(Ref* pSender);

	virtual void resetHatPosition() {}

	~BasicScene();

	static const int TYPE_ACTOR = 0; 
	static const int TYPE_HAT = 1;
	static const int TYPE_FAN = 2;
	static const int TYPE_BARRIER = 3;

protected:
	CollisionController cc;
	int max_barrier_tag;
	int max_fan_tag;

private:
	bool is_win;
	
};

#endif