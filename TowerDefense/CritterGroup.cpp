#include "stdafx.h"
#include "CritterGroup.h"


CritterGroup::CritterGroup(void)
{
}


CritterGroup::~CritterGroup(void)
{
}


void CritterGroup::generateCritters(int size, int level)
{
	for (int i = 0; i < size; i++)
	{
		Critter *critter = new Critter(level, n);
		_critters.push_back(critter);
	}
}


void CritterGroup::addStartingNode(Node* n)
{
	this->n = n;
}


bool CritterGroup::areAllDead()
{
	for (int i = 0; i < _critters.size(); i++)
	{
		// if at least ONE critter is not dead, return false
		if(_critters.at(i) != NULL)
		{
			if (!_critters[i]->isDead())
				return false;
		}
		
	}
	return true;
}


std::vector<Critter*> CritterGroup::getCritters()
{
	return _critters;
}
