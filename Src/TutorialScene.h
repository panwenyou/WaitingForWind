/* Waiting For Wind  @ Team WDLang

   统一命名规则：
   1.类名首字母大写
   2.方法名（函数名）首字母小写，接下来的每个独立单词首字母大写，如： addChild(), runAction()等等
   3.变量名全小写，单词间用下划线分割，如：x_position, y_position等等。
   
   TutorialScene程序设计师须知：
   1.此类作用是创建玩法介绍场景。
   2.我们可以利用一张大图片（上面有文字与图片）表示玩法即可。
   3.此场景必须添加返回按钮，并为其注册回调函数。
   */

#ifndef TUTORIAL_SCENE
#define TUTORIAL_SCENE

#include "cocos2d.h"
#include "BasicScene.h"

USING_NS_CC;

class TutorialScene : public BasicScene
{
public:
	static Scene* createScene();
	virtual void resetHatPosition();
	virtual bool init();

	CREATE_FUNC(TutorialScene);
};

#endif

