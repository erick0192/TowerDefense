#pragma once
//  <added pragmas>
#include <vector>
#include "Critter.h"
#include "DistanceMethods.h"
//  </added pragmas>
class Strategy
{
public:
	Strategy(void);
	~Strategy(void);

public:
	virtual int execute(int x, int y, int range, std::vector<Critter*> critters) = 0;
};

