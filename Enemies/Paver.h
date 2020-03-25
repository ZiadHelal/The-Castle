#pragma once
#include "Enemy.h"
class Paver :public Enemy
{
public:
	Paver(REGION R);
	virtual string PrintInfo();
};