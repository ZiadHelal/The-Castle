#include "Enemy.h"


Enemy::Enemy(color r_c, REGION r_region, int d)
{
	Clr = r_c;
	Region = r_region;
	SetDistance(d);
}

Enemy::~Enemy()
{
}

color Enemy::GetColor() const
{
	return Clr;
}

REGION Enemy::GetRegion() const
{
	return Region;
}

void Enemy::DecrementDist()
{
	if (Distance > MinDistance)
		Distance--;
}

void Enemy::SetDistance(int d)
{
	if (d >= MinDistance && d <= MaxDistance)
		Distance = d;
	else
		Distance = MaxDistance;
}

int Enemy::GetDistance() const
{
	return Distance;
}

void Enemy::SetID(int id)
{
	ID = id;
}

void Enemy::SetATK_Time(int a)
{
	ATK_Time = a;
}

void Enemy::SetFire(int f)
{
	Fire_Power = f;
}

void Enemy::SetH(double h)
{
	Health = h;
}

void Enemy::SetState(int s)
{
	State = s;
}

void Enemy::SetREG(REGION R)
{
	Region = R;
}

void Enemy::SetArrival(int a)
{
	ArrivalTime = a;
}

void Enemy::SetReload(int r)
{
	ReloadTime = r;
}

void Enemy::Kill()
{
	Health = 0;
}

bool Enemy::isActive(int current)
{
	return(ArrivalTime <= current && Health > 0);
}

string Enemy::Region1(REGION R)
{
	if (R == A_REG)
		return"A";
	if (R == B_REG)
		return "B";
	if (R == C_REG)
		return "C";
	return "D";
}