/* Waiting For Wind

   统一命名规则：
   1.类名首字母大写
   2.方法名（函数名）首字母小写，接下来的每个独立单词首字母大写，如： addChild(), runAction()等等
   3.变量名全小写，单词间用下划线分割，如：x_position, y_position等等。*/

#ifndef GAME_SCENE4_H
#define GAME_SCENE4_H

#include "BasicScene.h"
#include "Drama.h"

class GameScene4 : public BasicScene
{
private:
	Vector<Drama*> dramaList;
public:
	virtual bool init();
	virtual void resetHatPosition();
	static Scene* createScene();
	CREATE_FUNC(GameScene4);
};

#endif
