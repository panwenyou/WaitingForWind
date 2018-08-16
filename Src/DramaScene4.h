/* Waiting For Wind

   统一命名规则：
   1.类名首字母大写
   2.方法名（函数名）首字母小写，接下来的每个独立单词首字母大写，如： addChild(), runAction()等等
   3.变量名全小写，单词间用下划线分割，如：x_position, y_position等等。*/

#ifndef DRAMASCENE4_H
#define DRAMASCENE4_H

#include "cocos2d.h"
#include "Drama.h"
#include "GameScene4.h"

USING_NS_CC;

class DramaScene4 : public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	void update(float dt);
	CREATE_FUNC(DramaScene4);
};

#endif