#pragma once

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"

// Enemy is the base class of each type of enemy
// Enemy is an abstract class.
class Enemy
{

protected:
	int ID;         //Each enemy has a unique ID (sequence number)
	color Clr;	    //Color of the enemy (will be set depending on the enemy type: Paver, ...etc.)
	REGION Region;  //Region of this enemy
	int Distance;	//Horizontal distance between enemy & the tower of its region
	                //Always positive (ranges from 2 to 60)
	double Health;	//Enemy health
	int State;		
	int ATK_Time;
	int Fire_Power;
	int ArrivalTime;
	int ReloadTime;
	//
	// TODO: Add More Data Members As Needed
	//

public:
	Enemy(color r_c, REGION r_region, int d = MaxDistance);
	virtual ~Enemy();

	color GetColor() const;
	REGION GetRegion() const;

	void DecrementDist();

	void SetDistance(int d);
	int GetDistance() const;

	void SetID(int id);
	void SetH(double h);
	void SetState(int s);
	void SetATK_Time(int a);
	void SetFire(int f);
	void SetREG(REGION R);
	void SetArrival(int a);
	void SetReload(int r);
	void Kill();
	bool isActive(int current);
	virtual string PrintInfo() = 0;
	string Region1(REGION R);
	// Virtual Functions: ----------------

	//virtual void Move() = 0;	    //All enemies can move
	//virtual void Attack() = 0;	//All enemies can attack (attacking is paving or shooting)

	//
	// TODO: Add More Member Functions As Needed
	//

};