/* Waiting For Wind

   统一命名规则：
   1.类名首字母大写
   2.方法名（函数名）首字母小写，接下来的每个独立单词首字母大写，如： addChild(), runAction()等等
   3.变量名全小写，单词间用下划线分割，如：x_position, y_position等等。

   CollisionController程序设计师须知:
   1.最好不要改动已定义的方法的名字,如要改动，请告知
   2.其余的函数由程序设计师自己定义。
   */

#ifndef COLLISION_CONTROLLER_H
#define COLLISION_CONTROLLER_H

#include "Actor.h"
#include "Barrier.h"
#include "Hat.h"
#include "Fan.h"
#include <math.h>//自加

struct Area {
public:
	Vec2 left_top;
	Vec2 botton_down;
	Area() {
		left_top = Vec2(0.0f, 0.0f);
		botton_down = Vec2(0.0f, 0.0f);
	}
};

class CollisionController
{
public:
	CollisionController(void) : hat(nullptr), actor(nullptr) {}
	~CollisionController(void);
	
	// 添加Hat实例指针
	void addHat(Hat* h);

	// 添加Hat实例指针
	void addActor(Actor* ac);

	// 检查是否达到胜利条件
	bool isWin();

	void clean();


private:
	Hat* hat;
	Actor* actor;
};

#endif

