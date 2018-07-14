#include "Character.h"
#include "Hero.h"

// ko nên sử dụng USING_NS_CC 

Character::Character()
{

}

Character::~Character()
{

}

cocos2d::Scene *Character::createScene()
{
	cocos2d::Scene *scene = cocos2d::Scene::create();
	Character *layer = Character::create();
	scene->addChild(layer);
	return scene;
}

bool Character::init()
{
	if (!cocos2d::Scene::init())
	{
		return false;
	}

	cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	// Create chracter.
	/*Hero::create();*/
	cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Animation_Bear/AnimBear.plist");
	spriteSheet = cocos2d::SpriteBatchNode::create("Animation_Bear/AnimBear.png");
	this->addChild(spriteSheet);

	cocos2d::Sprite *bear = cocos2d::Sprite::createWithSpriteFrameName("bear1.png");
	bear->setPosition(cocos2d::Point(visibleSize.width / 2, visibleSize.height / 2));
	spriteSheet->addChild(bear);

	cocos2d::Animate *anime = cocos2d::Animate::create(Hero::hero_Ide("bear", 8, 1.0f / 30.f));
	anime->retain();
	bear->runAction(cocos2d::RepeatForever::create(anime));

	return true;
}