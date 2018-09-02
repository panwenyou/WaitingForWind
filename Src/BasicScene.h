/* Waiting For Wind  @ Team WDLang

   ͳһ��������
   1.��������ĸ��д
   2.��������������������ĸСд����������ÿ��������������ĸ��д���磺 addChild(), runAction()�ȵ�
   3.������ȫСд�����ʼ����»��߷ָ�磺x_position, y_position�ȵȡ�
   
   BasicScene�������ʦ��֪��
   1.���е���Ϸ�����涼Ҫ�̳д��࣬���������init�������ȵ��ñ����init������
   2.����ʹ���Ѿ�ʵ�ֺ��˵�MainGameMenu�Լ�CollisionController��������Ϸ�߼���
   3.tagֵ���䡣0-Hat, 1-Actor 10~19-Fan 20~100-barrier
   */

#ifndef BASIC_SCENE_H
#define BASIC_SCENE_H

#include "cocos2d.h"
#include "CollisionController.h"
#include "MainGameMenu.h"
#include "Actor.h"
#include "Hat.h"
#include "Leaves.h"
#include "Fan.h"
#include "Barrier.h"
#include "WinningLayer.h"
#include "ui/CocosGUI.h"
#include "cocos-ext.h"
#include "BarrierController.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

class BasicScene : public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(BasicScene);

public:
	// ʤ��ʱ���õĺ���������ʤ������������ѡ�س���
	void onWinning();

	// ÿһ֡�Ļص�
	void update(float dt);
	void adjustPerFrame();

	// ÿ5�����Ȼ��
	void natrualWindComes(float dt);

	// ����ӽڵ�
	void myAddChild(Sprite* s, const int type);

	// ����·�������
	void addPowerList();

	// ���ذ�ť�ص�
	void onBackCallBack(Ref* pSender);
	void onReplayCallBack(Ref* pSender);

	virtual void resetHatPosition() {}

	// ���BarrierControllerʵ��
	BarrierController* getBarrierController();

	~BasicScene();

	static const int TYPE_ACTOR = 0; 
	static const int TYPE_HAT = 1;
	static const int TYPE_FAN = 2;
	static const int TYPE_BARRIER = 3;

protected:
	CollisionController cc;
	BarrierController bc;
	int max_barrier_tag;
	int max_fan_tag;

private:
	bool is_win;
	
};

#endif