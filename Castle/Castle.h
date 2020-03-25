#pragma once

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\GUI\GUI.h"

#include "Tower.h"

class Castle
{
	Tower Towers[NoOfRegions];


	//
	// TODO: Add More Data Members As Needed
	//
	
public:

	Castle();
	void SetTowersHealth(double h);
	void SetTowerNO(int n);
	void SetTowerFP(int fp);
	string PrintInfo(int n);

	//
	// TODO: Add More Member Functions As Needed
	//
};
