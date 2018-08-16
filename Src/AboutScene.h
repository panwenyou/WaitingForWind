/* Waiting For Wind

   统一命名规则：
   1.类名首字母大写
   2.方法名（函数名）首字母小写，接下来的每个独立单词首字母大写，如： addChild(), runAction()等等
   3.变量名全小写，单词间用下划线分割，如：x_position, y_position等等。*/

#ifndef ABOUT_SCENE_H
#define ABOUT_SCENE_H

#include "cocos2d.h"

USING_NS_CC;

/*
   About Scene负责显示我们开发小组的
   信息。包括小组名和每个成员的名字
*/
class AboutScene : public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	
	void onBack(Ref* pSender);

	CREATE_FUNC(AboutScene);
};

#endif