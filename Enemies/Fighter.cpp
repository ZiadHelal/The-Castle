#include "Fighter.h"



Fighter::Fighter(REGION R):Enemy(DARKOLIVEGREEN,R)
{
}

string Fighter::PrintInfo()
{
	return ("Type: Fighter, Health = " + to_string(Health) + " Fire Power = " + to_string(Fire_Power) + " Reload period = " + to_string(ReloadTime) + " Region: " + Region1(Region));
}