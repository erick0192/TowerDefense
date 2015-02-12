#pragma once
#include "strategy.h"
class CheckNearEnd :
	public Strategy
{
public:
	CheckNearEnd(void);
	~CheckNearEnd(void);
public:
	int execute(int x, int y, int range, std::vector<Critter*> critters);
};

