#include "stdafx.h"
#include "CheckNearEnd.h"


CheckNearEnd::CheckNearEnd(void)
{
}


CheckNearEnd::~CheckNearEnd(void)
{
}

int CheckNearEnd::execute(int x, int y, int range, std::vector<Critter*> critters)
{
	Critter* nearestToEnd = critters[0];
	int nearestToEndIndex = -1;

	CPoint p1(x, y);
	for(int i=0; i<critters.size(); i++)
		if( DistanceMethods::withinRange( critters[i]->getPosition(), p1, range ) )
		{
			nearestToEnd = critters[i];
			nearestToEndIndex = i;
			break;
		}

	if(nearestToEndIndex == -1)
		return nearestToEndIndex;

	for(int i= nearestToEndIndex + 1; i<critters.size(); i++)
		if( DistanceMethods::withinRange( critters[i]->getPosition(), p1, range ) )
			if( DistanceMethods::distance(critters[i]->getPosition(), p1) > DistanceMethods::distance(nearestToEnd->getPosition(), p1) )
			{
				nearestToEnd = critters[i];
				nearestToEndIndex = i;
			}
	return nearestToEndIndex;
}