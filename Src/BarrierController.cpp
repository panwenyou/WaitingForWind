#include "BarrierController.h"

void BarrierController::addBarrier(Barrier* b) {
	this->vec.pushBack(b);
}

void BarrierController::destroyAll() {
	for (int i = 0; i < vec.size(); i++) {
		vec.at(i)->destroyAnimation();
	}
}


void BarrierController::checkHitAll() {

}
