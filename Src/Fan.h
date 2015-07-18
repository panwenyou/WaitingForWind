/* Waiting For Wind

统一命名规则：
1.类名首字母大写
2.方法名（函数名）首字母小写，接下来的每个独立单词首字母大写，如： addChild(), runAction()等等
3.变量名全小写，单词间用下划线分割，如：x_position, y_position等等。

风扇类Fan
Fan类程序设计师须知以下规则：
1.如何获得当前Layer的Hat实例： 规定Hat实例的tag=0，只需调用this->getParent()->getChildByTag(0);
2.Fan类除了create函数，不需向外提供任何接口，里面的所有函数命名由程序设计师自己规定。
*/

#ifndef FAN_H
#define FAN_H

#include "cocos2d.h"

USING_NS_CC;

/* Fan必须实现以下功能
1.分发点击事件到实例中。
2.在点击响应函数中，计算吹风范围并将范围内的Hat吹起，并执行吹的动画。
3.额外的，Fan不需要提供任何对外接口
4.如果程序设计师改动了create接口，请告知*/

class Fan : public Sprite
{
public:
	Fan(void);
	~Fan(void);

	/* create函数功能如下：
	根据输入的direction来创建具有相应图片的Fan实例。*/
	static Fan* create(const int direction);
	
	//开始触摸  
	virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
	//触摸结束  
	virtual void onTouchEnded(Touch *pTouch, Event *pEvent);

	
	// 指示方向
	static const int NORTH = 1;
	static const int NORTH_EAST = 2;
	static const int EAST = 3;
	static const int SOUTH_EAST = 4;
	static const int SOUTH = 5;
	static const int SOUTH_WEST = 6;
	static const int WEST = 7;
	static const int NORTH_WEST = 8;
	void setDirection(int d);

private:
	int direction;
};

#endif

