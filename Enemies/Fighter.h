#pragma once
#include "Enemy.h"
class Fighter :public Enemy
{
public:
	Fighter(REGION R);
	virtual string PrintInfo();
};