/* Waiting For Wind  @ Team WDLang

   统一命名规则：
   1.类名首字母大写
   2.方法名（函数名）首字母小写，接下来的每个独立单词首字母大写，如： addChild(), runAction()等等
   3.变量名全小写，单词间用下划线分割，如：x_position, y_position等等。
   
   StageChoosingScene程序设计师须知：
   1.这个类是为了在每5秒的自然风中表现过场动画。
   */

#ifndef LEAVES_H
#define LEAVES_H

#include "cocos2d.h"

USING_NS_CC;

class Leaves : public Sprite
{
public:
	Leaves(void);
	~Leaves(void);

	static Leaves* create(int leaves_num);
};

#endif

