#include "Hero.h"

Hero::Hero()
{

}

Hero::~Hero()
{

}

//Hero * Hero::create()
//{
//	cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Animation_Bear/AnimBear.plist");
//	cocos2d::SpriteBatchNode *spriteSheet = cocos2d::SpriteBatchNode::create("Animation_Bear/AnimBear.png");
//
//	return nullptr;
//}

cocos2d::Animation *Hero::hero_Ide(std::string prefixName, int pFamesOrder, float delay)
{
	cocos2d::Vector<cocos2d::SpriteFrame*> aniframe;

	for (int i = 1; i <= pFamesOrder; i++)
	{
		char buffer[10];
		sprintf(buffer, "%d.png", i);
		std::string str = prefixName + buffer;
		auto frame = cocos2d::SpriteFrameCache::getInstance()->getSpriteFrameByName(str);
		aniframe.pushBack(frame);
	}

	cocos2d::Animation *animation = cocos2d::Animation::createWithSpriteFrames(aniframe, delay);
	return animation;
}