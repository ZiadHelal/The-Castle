#include "Tower.h"
#include<iostream>
#include<string>


void Tower::SetHealth(double h)
{
	if(h > 0)
		Health = h;
	else
		Health = 0; // killed
}

double Tower::GetHealth() const
{
	return Health;
}

void Tower::SetNO(int n)
{
	NO_Enemies = (n > 0 ? n : 1);
}

int Tower::GetNO() const
{
	return NO_Enemies;
}

void Tower::SetFP(int fp)
{
	Fire_Power = (fp > 0 ? fp : 1);
}

int Tower::GetFP() const
{
	return Fire_Power;
}

string Tower::PrintInfo()
{
	return "Tower Health = " + to_string(Health) + " , Number of Enemies = " + to_string(NO_Enemies) + " , Fire Power = " + to_string(Fire_Power);
}