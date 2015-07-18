#include "Leaves.h"


Leaves::Leaves(void)
{
}


Leaves::~Leaves(void)
{
}

Leaves* Leaves::create(int leaves_num)
{
	auto leaves = new Leaves();

	auto str = String::createWithFormat("Leaves%d.png", leaves_num);

	if (leaves != nullptr && leaves->initWithFile(str->getCString()))
	{
		leaves->autorelease();
	}
	else
	{
		delete leaves;
		leaves = nullptr;
	}
	return leaves;
}
