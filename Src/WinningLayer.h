#ifndef WINNING_LAYER_H
#define WINNING_LAYER_H

#include "cocos2d.h"

USING_NS_CC;

class WinningLayer : public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(WinningLayer);

	void onOkCallBack(Ref* pSender);
};

#endif

