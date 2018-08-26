/* Waiting For Wind

   ͳһ�������
   1.��������ĸ��д
   2.��������������ĸСд���������ÿ������������ĸ��д���磺 addChild(), runAction()�ȵ�
   3.�����ȫСд�����ʼ����»��߷ָ�磺x_position, y_position�ȵȡ�*/

#ifndef ABOUT_SCENE_H
#define ABOUT_SCENE_H

#include "cocos2d.h"

USING_NS_CC;

/*
   About Scene������ʾ���ǿ���С���
   ��Ϣ�����С�����ÿ���Ա������
*/
class AboutScene : public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	
	void onBack(Ref* pSender);

	CREATE_FUNC(AboutScene);
};

#endif