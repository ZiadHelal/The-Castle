#pragma once
#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\GUI\GUI.h"

class Tower
{
	double Health;		//Tower Health
	int NO_Enemies;		//Maximum number of enemies a tower can fight
	int Fire_Power;		//Tower Fire Power
	int distance_paved;
	int t_killed_enemy;
	//
	// TODO: Add More Data Members As Needed
	//

public:

	void SetHealth(double h);
	double GetHealth() const;
	void SetNO(int n);
	int GetNO() const;
	void SetFP(int fp);
	int GetFP() const;
	string PrintInfo();
	//
	// TODO: Add More Member Functions As Needed
	//

};

