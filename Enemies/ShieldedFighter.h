#pragma once
#include "Enemy.h"
class Shielded :public Enemy
{
	double Priority;
public:
	Shielded(REGION R);
	virtual string PrintInfo();
};