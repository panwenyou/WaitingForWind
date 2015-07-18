/* Waiting For Wind  @ Team WDLang

   统一命名规则：
   1.类名首字母大写
   2.方法名（函数名）首字母小写，接下来的每个独立单词首字母大写，如： addChild(), runAction()等等
   3.变量名全小写，单词间用下划线分割，如：x_position, y_position等等。
   
   StageChoosingScene程序设计师须知：
   1.此类作用是选择关卡。
   2.程序设计师必须为每个选择按钮添加回调函数，并同时创建对应的关卡场景。
   3.此场景必须添加返回按钮，并为其注册回调函数。
   */

#ifndef STAGECHOOSINGSCENE
#define STAGECHOOSINGSCENE

#include "cocos2d.h"
#include "DramaScene.h"
#include "DramaScene2.h"
#include "DramaScene4.h"

USING_NS_CC;

class StageChoosingScene : public Layer
{
public:
	static int stageNum;

public:
	static Scene* createScene();

	virtual bool init();


	void initMenu();


	void onLuffyStage1(Ref* pSender);
	void onLuffyStage2(Ref* pSender);
	void onWindComesStage1(Ref* pSender);
	void onBack(Ref* pSender);

	CREATE_FUNC(StageChoosingScene);
};

#endif

