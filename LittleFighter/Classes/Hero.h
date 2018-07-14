#ifndef _HERO_
#define _HERO_
#include "cocos2d.h"
#include <string>

class Hero : public cocos2d::Sprite
{
public:
	Hero();
	~Hero();

	/*static Hero *create();*/

	static cocos2d::Animation *hero_Ide(std::string prefixName, int pFamesOrder, float delay);

private:
	
};
#endif // !_HERO_
