#include "ShieldedFighter.h"



Shielded::Shielded(REGION R) :Enemy(ORANGERED, R)
{
}

string Shielded::PrintInfo()
{
	return ("Type: Shielded, Health = " + to_string(Health) + " Fire Power = " + to_string(Fire_Power) + " Reload period = " + to_string(ReloadTime) + " Region: " + Region1(Region));
}