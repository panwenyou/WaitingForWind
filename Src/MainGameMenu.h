/* Waiting For Wind

   统一命名规则：
   1.类名首字母大写
   2.方法名（函数名）首字母小写，接下来的每个独立单词首字母大写，如： addChild(), runAction()等等
   3.变量名全小写，单词间用下划线分割，如：x_position, y_position等等。
   
   程序设计师须知：
   1.不要改动已声明的方法名称，如改动，请告知
   */

#ifndef MAIN_GAME_MENU_H
#define MAIN_GAME_MENU_H

#include "cocos2d.h"
#include "BasicScene.h"

USING_NS_CC;

class MainGameMenu
{
public:
	MainGameMenu(void) : game_menu(nullptr) {}
	~MainGameMenu(void);

	// 初始化game_menu，向game_menu中添加MenuItem并且为MenuItem注册回调函数
	bool init();

	Menu* getGameMenu();

	void onBackItem(Ref* pSender);
	void onReplayItem(Ref* pSender);

private:
	Menu* game_menu;
};

#endif

