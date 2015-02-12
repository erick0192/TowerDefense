#include "stdafx.h"
#include "CheckNearTower.h"


CheckNearTower::CheckNearTower(void)
{
}


CheckNearTower::~CheckNearTower(void)
{
}


int CheckNearTower::execute(int x, int y, int range, std::vector<Critter*> critters)
{
	Critter* nearest = critters[0];
	int nearestIndex = -1;

	CPoint p1(x, y);
	for(int i=0; i<critters.size(); i++)
		if( DistanceMethods::withinRange( critters[i]->getPosition(), p1, range ) )
		{
			nearest = critters[i];
			nearestIndex = i;
			break;
		}

	if(nearestIndex == -1)
		return nearestIndex;

	for(int i= nearestIndex + 1; i<critters.size(); i++)
		if( DistanceMethods::withinRange( critters[i]->getPosition(), p1, range ) )
			if( DistanceMethods::distance(critters[i]->getPosition(), p1) < DistanceMethods::distance(nearest->getPosition(), p1) )
			{
				nearest = critters[i];
				nearestIndex = i;
			}
	return nearestIndex;
}