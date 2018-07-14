#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

cocos2d::Scene* HelloWorld::createScene()
{
	cocos2d::Scene *scene = cocos2d::Scene::create();
	HelloWorld *layer = HelloWorld::create();
	scene->addChild(layer);
    return scene;
}

bool HelloWorld::init()
{
    if ( !cocos2d::Scene::init() )
    {
        return false;
    }

	cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	// Close.
	cocos2d::MenuItemImage *closeItem = cocos2d::MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
	float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
	float y = origin.y + closeItem->getContentSize().height / 2;
	closeItem->setPosition(cocos2d::Vec2(x, y));

	cocos2d::Menu *menu = cocos2d::Menu::create(closeItem, NULL);
    menu->setPosition(cocos2d::Vec2::ZERO);
    this->addChild(menu, 1);

	//
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
	cocos2d::Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
