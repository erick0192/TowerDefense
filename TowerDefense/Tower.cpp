#include "stdafx.h"
#include "Tower.h"


Tower::Tower(void)
{
}


Tower::~Tower(void)
{
}

Tower::Tower(int level)
{
}

Tower::Tower(int x, int y, int level)
{
}

Tower::Tower(Strategy* initStrategy){
	strategy = initStrategy;
}

void Tower::setX(int x)
{
	x = x;
}

void Tower::setY(int y)
{
	y = y;
}

int Tower::getX()
{
	return x;
}
int Tower::getY()
{
	return y;
}

void Tower::setStrategy(Strategy* newStrategy){
	strategy = newStrategy;
}

int Tower::executeStrategy(vector<Critter*> critters)
{
	return this->strategy->execute(x, y, _range, critters);
}