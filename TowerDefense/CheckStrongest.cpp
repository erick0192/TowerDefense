#include "stdafx.h"
#include "CheckStrongest.h"


CheckStrongest::CheckStrongest(void)
{
}


CheckStrongest::~CheckStrongest(void)
{
}


int CheckStrongest::execute(int x, int y, int range, std::vector<Critter*> critters)
{
	Critter* strongest = critters[0];
	int strongestIndex = -1;

	CPoint p1(x, y);
	for(int i=0; i<critters.size(); i++)
		if( DistanceMethods::withinRange( critters[i]->getPosition(), p1, range ) )
		{
			strongest = critters[i];
			strongestIndex = i;
			break;
		}

	if(strongestIndex == -1)
		return strongestIndex;
	

	for(int i=strongestIndex + 1; i < critters.size(); i++)
		if( DistanceMethods::withinRange( critters[i]->getPosition(), p1, range ) )
			if(critters[i]->getHitpoints() > strongest->getHitpoints())
			{
				strongest = critters[i];
				strongestIndex = i;
			}
	return strongestIndex;
}