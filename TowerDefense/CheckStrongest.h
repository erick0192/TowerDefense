#pragma once
#include "strategy.h"
class CheckStrongest :
	public Strategy
{
public:
	CheckStrongest(void);
	~CheckStrongest(void);
public:
	int execute(int x, int y, int range, std::vector<Critter*> critters);

};

