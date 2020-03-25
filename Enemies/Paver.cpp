#include "Paver.h"



Paver::Paver(REGION R) :Enemy(DARKBLUE, R)
{
}

string Paver::PrintInfo()
{
	return ("Type: Paver, Health = " + to_string(Health) + " Paver for time step = " + to_string(Fire_Power) + " Reload period = " + to_string(ReloadTime) + " Region: " + Region1(Region));
}