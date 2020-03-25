#include "Castle.h"

#include "..\GUI\GUI.h"

Castle::Castle()
{
}

void Castle::SetTowersHealth(double h)
{
	for (int i = 0; i < NoOfRegions; i++)
	{
		Towers[i].SetHealth(h);
	}
}

void Castle::SetTowerNO(int n)
{
	for (int i = 0; i < NoOfRegions; i++)
	{
		Towers[i].SetNO(n);
	}
}

void Castle::SetTowerFP(int fp)
{
	for (int i = 0; i < NoOfRegions; i++)
	{
		Towers[i].SetFP(fp);
	}
}

string Castle::PrintInfo(int n)
{
	if (n == 1)
	{
		return Towers[0].PrintInfo();
	}
	else if (n == 2)
	{
		return Towers[1].PrintInfo();
	}
	else if (n == 3)
	{
		return Towers[2].PrintInfo();
	}
	return Towers[3].PrintInfo();
}