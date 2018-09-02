#ifndef BARRIERCONTROLLER_H
#define BARRIERCONTROLLER_H

#include "cocos2d.h"
#include "Barrier.h"

USING_NS_CC;

class BarrierController {
private:
	Vector<Barrier*> vec;
public:
	BarrierController() {}
	~BarrierController() { vec.clear(); }

	void addBarrier(Barrier* b);
	void destroyAll();
	void checkHitAll();
};

#endif