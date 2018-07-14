#ifndef _CHARACTER_
#define _CHARACTER_
#include "cocos2d.h"

class Character : public cocos2d::Scene
{
public:
	Character();
	~Character();

	static cocos2d::Scene *createScene();

	virtual bool init();

	CREATE_FUNC(Character);

private:
	cocos2d::SpriteBatchNode *spriteSheet;
};
#endif // !_CHARACTER_
