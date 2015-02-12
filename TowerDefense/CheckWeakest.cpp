#include "stdafx.h"
#include "CheckWeakest.h"


CheckWeakest::CheckWeakest(void)
{
}


CheckWeakest::~CheckWeakest(void)
{
}


int CheckWeakest::execute(int x, int y, int range, std::vector<Critter*> critters)
{
	Critter* weakest = critters[0];
	int weakestIndex = -1;

	CPoint p1(x, y);
	for(int i = 0; i < critters.size(); i++)
		if( DistanceMethods::withinRange( critters[i]->getPosition(), p1, range ) )
		{
			weakest = critters[i];
			weakestIndex = i;
			break;
		}

	if(weakestIndex == -1)
		return weakestIndex;
	

	for(int i=weakestIndex + 1; i < critters.size(); i++)
		if( DistanceMethods::withinRange( critters[i]->getPosition(), p1, range ) )
			if(critters[i]->getHitpoints() < weakest->getHitpoints())
			{
				weakest = critters[i];
				weakestIndex = i;
			}
	return weakestIndex;
}