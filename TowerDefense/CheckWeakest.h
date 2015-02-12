#pragma once
#include "strategy.h"
class CheckWeakest :
	public Strategy
{
public:
	CheckWeakest(void);
	~CheckWeakest(void);
public:
	int execute(int x, int y, int range, std::vector<Critter*> critters);
};

