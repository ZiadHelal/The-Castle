#include "Battle.h"
#include "GUI\GUI.h"
#include"Data Structures\LinkedList.h"
#include"Data Structures\Queue.h"
#include"Enemies\Fighter.h"
#include"Enemies\Paver.h"
#include"Enemies\ShieldedFighter.h"
#include<fstream>
#include<iostream>

void Simulator();

int main()
{

	//
	// THIS IS JUST A DEMO
	// THIS MAIN SHOULD BE CHANGED IN PHASE 1 AND PHASE 2
	//
	/*
	Battle* pGameBattle = new Battle;

	GUI * pGUI = new GUI;

	pGUI->PrintMessage("This is Just a Demo. Click to Move to the Next Time Step ...");

	//intialize health of the towers with 200
	pGameBattle->GetCastle()->SetTowersHealth(200);
	 
	// Declare some enemies and fill their data
	// In the game, enemies should be loaded from an input file
	// and should be dynamically allocated
	Enemy e1(DARKBLUE, A_REG, 6);
	Enemy e2(DARKBLUE, D_REG, 60);
	Enemy e3(DARKOLIVEGREEN, B_REG, 30); 
	Enemy e4(DARKOLIVEGREEN, A_REG, 4);
	Enemy e5(ORANGERED, C_REG, 19); 
	Enemy e6(ORANGERED, C_REG, 30); 
	Enemy e7(ORANGERED, A_REG, 2);
	Enemy e8(DARKOLIVEGREEN, C_REG, 7); 
	Enemy e9(ORANGERED, A_REG, 30); 
	Enemy e10(DARKBLUE, C_REG, 4); 

	// Adding the enemies to the battle
	pGameBattle->AddEnemy(&e1);
	pGameBattle->AddEnemy(&e2);
	pGameBattle->AddEnemy(&e3);
	pGameBattle->AddEnemy(&e4);
	pGameBattle->AddEnemy(&e5);
	pGameBattle->AddEnemy(&e6);
	pGameBattle->AddEnemy(&e7);
	pGameBattle->AddEnemy(&e8);
	pGameBattle->AddEnemy(&e9);
	pGameBattle->AddEnemy(&e10);

	// Drawing the battle enemies
	pGameBattle->DrawEnemies(pGUI);

	Point p;
	pGUI->GetPointClicked(p);
	
	// Now a demo to move enemies some time steps
	// TimeStep is a normal integer that is incremented each time by 1
	for(int TimeStep = 1 ; TimeStep <= 10 ; TimeStep++)
	{
		// Clear for redrawing
		pGUI->ClearStatusBar();
		pGUI->ClearBattleArea();
		pGUI->DrawCastle();

		// Decrement the distance of each enemy
		e1.DecrementDist();
		e2.DecrementDist();
		e3.DecrementDist();
		e4.DecrementDist();
		e5.DecrementDist();
		e6.DecrementDist();
		e7.DecrementDist();
		e8.DecrementDist();
		e9.DecrementDist();
		e10.DecrementDist();

		// Redraw the enemies
		pGameBattle->DrawEnemies(pGUI);

		pGUI->GetPointClicked(p);
	}

	delete pGUI;
	delete pGameBattle;
	*/
	Simulator();

	return 0;
}

REGION REG_TO_CHAR(char c)
{
	if (c == 'A')
		return A_REG;
	if (c == 'B')
		return B_REG;
	if (c == 'C')
		return C_REG;
	return D_REG;
}

void loading(/*ifstream &input, */double &C1, double &C2, double &C3, Battle *ptr, Queue<Enemy*> &Q)
{
	ifstream input("in.txt");
	int h;
	int ne;
	int ts;
	input >> h >> ne >> ts;
	ptr->GetCastle()->SetTowersHealth(h);
	ptr->GetCastle()->SetTowerNO(ne);
	ptr->GetCastle()->SetTowerFP(ts);
	int S, TYP, T, H, POW, RLD;
	char R;
	input >> C1 >> C2 >> C3;
	REGION Reg;
	input >> S;
	while (S != -1)
	{
		input >> TYP >> T >> H >> POW >> RLD >> R;
		Enemy* E;
		if (TYP == 0)
		{
			E = new Paver(REG_TO_CHAR(R));
		}
		else if (TYP == 1)
		{
			E = new Fighter(REG_TO_CHAR(R));
		}
		else if (TYP == 2)
		{
			E = new Shielded(REG_TO_CHAR(R));
		}
		E->SetH(H);
		E->SetFire(POW);
		E->SetID(S);
		E->SetArrival(T);
		E->SetReload(RLD);
		Q.enqueue(E);
		input >> S;
	}
	input.close();
}

void Simulator()
{
	Point p;
	Battle* pGameBattle = new Battle;
	GUI * pGUI = new GUI;
	Queue<Enemy*> InActive;
	Queue<Enemy*> Killed;
	LinkedList<Enemy*> Active;
	//pGUI->PrintMessage("Enter File Name: ");
	//string s = pGUI->GetString();
	//s += ".txt";
	//pGUI->GetPointClicked(p);
	//pGUI->ClearStatusBar();
	ifstream input("in.txt");
	double C1, C2, C3;
	loading(/*input,*/ C1, C2, C3, pGameBattle, InActive);
	int time = 1;
	int pos = 1;
	int killed = 0;
	int active = 0;
	string msg;
	while (!InActive.isEmpty())
	{
		pGUI->GetPointClicked(p);
		msg = "Towers Info : " + pGameBattle->GetCastle()->PrintInfo(1);
		while (InActive.peekFront()->isActive(time))
		{
			Active.insert(pos, InActive.peekFront());
			msg += InActive.peekFront()->PrintInfo() + "\n";
			InActive.dequeue();
			pos++;
			active++;
		}
		msg += "Total Number of Active enemies = " + to_string(active) + "\n";
		if (active > 0)
		{
			killed++;
			Killed.enqueue(Active.getEntry(1));
			msg += Active.getEntry(1)->PrintInfo() + "\n";
			Active.remove(1);
			active--;
			pos--;
		}
		msg += "Total Number of Killed Enemies = " + to_string(killed) + "\n";
		std::cout << msg;
		pGUI->PrintMessage(msg);
		time++;
		pGUI->GetPointClicked(p);
		pGUI->ClearStatusBar();
	}
	delete pGameBattle;
	delete pGUI;
}