/* Waiting For Wind

   统一命名规则：
   1.类名首字母大写
   2.方法名（函数名）首字母小写，接下来的每个独立单词首字母大写，如： addChild(), runAction()等等
   3.变量名全小写，单词间用下划线分割，如：x_position, y_position等等。*/

#ifndef ACTOR_H
#define ACTOR_H

#include "cocos2d.h"

USING_NS_CC;

class Actor : public Sprite
{
public:
	Actor(void);
	~Actor(void);

	// 改变胜利区域
	void changeWinningPoint(Vec2 anchor);
	void setPosition(float x, float y);
	Vec2 getWinningPoint();

	static Actor* create(int actor_num);

private:
	Vec2 winning_point;
};

#endif

