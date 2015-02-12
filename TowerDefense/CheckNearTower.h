#pragma once
#include "strategy.h"
class CheckNearTower :
	public Strategy
{
public:
	CheckNearTower(void);
	~CheckNearTower(void);
public:
	int execute(int x, int y, int range, std::vector<Critter*> critters);
};

