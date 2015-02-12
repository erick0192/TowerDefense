#pragma once
//	<added pragmas>
#include <vector>
#include "Critter.h"
//	</added pragmas>

class CritterGroup
{
public:
	CritterGroup(void);
	~CritterGroup(void);

public:
	void generateCritters(int size, int level);
	bool areAllDead();
	std::vector<Critter*> getCritters();
	void addStartingNode(Node* n);

private:
	std::vector<Critter*> _critters;
	int _currentIndexOfCritter;
	Node* n;
};

