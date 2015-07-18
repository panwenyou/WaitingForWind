/* Waiting For Wind @ Team WDLang

   统一命名规则：
   1.类名首字母大写
   2.方法名（函数名）首字母小写，接下来的每个独立单词首字母大写，如： addChild(), runAction()等等
   3.变量名全小写，单词间用下划线分割，如：x_position, y_position等等。*/

#ifndef HAT_H
#define HAT_H

#include "cocos2d.h"

USING_NS_CC;

class Hat : public Sprite
{
public:
	Hat(void);
	~Hat(void);

	void setVelocity(Vec2 velocity);
	void onRemove();
	void removeItself();
	void comeOut();

	static Hat* create(int hat_num);

	int hat_num;
};

#endif

