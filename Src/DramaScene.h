/* Waiting For Wind

   ͳһ�������
   1.��������ĸ��д
   2.��������������ĸСд���������ÿ������������ĸ��д���磺 addChild(), runAction()�ȵ�
   3.�����ȫСд�����ʼ����»��߷ָ�磺x_position, y_position�ȵȡ�*/

#ifndef DRAMASCENE_H
#define DRAMASCENE_H

#include "cocos2d.h"
#include "Drama.h"
#include "GameScene1.h"

USING_NS_CC;

class DramaScene : public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	void update(float dt);
	CREATE_FUNC(DramaScene);
};

#endif