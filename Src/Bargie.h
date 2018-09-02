#ifndef BARGIE_H
#define BARGIE_H


#include "Barrier.h"

class Bargie : public Barrier {
private:
	Size destroy_size;
	Vector<SpriteFrame*> vec;
public:
	Bargie() {}
	~Bargie() {}

	virtual bool init(int t);
	// Ïú»Ù¶¯»­
	virtual void destroyAnimation();

	static Bargie* create(int t);
};

#endif