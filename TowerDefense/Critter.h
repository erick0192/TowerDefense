#pragma once


#include "towerdefensedoc.h"

//	<added pragmas>
class Node;
//#include "LinkedList.h"
#include "TowerDefenseView.h"
//	</added pragmas>

class Critter :
	public CTowerDefenseDoc
{
public:
	Critter(void);
	~Critter(void);

public:
	Critter(int level, Node* head);

	void setReward(int reward);
	void setHitpoints(int hitpoints);
	void setStrength(int strength);
	void setLevel(int level);
	void setSpeed(int speed);
	void setDead(bool dead);
	void setPosition(CPoint position);

	int getReward();
	int getHitpoints();
	int getStrength();
	int getLevel();
	int getSpeed();

	bool isDead();
	void releaseCritter();
	CPoint getPosition();
    void isAttacked(int towerDamage);
	bool move();

private:
	int _reward;
	int _hitpoints;
	int _strength;
	int _speed;
	int _level;
	bool _dead;
	bool released;
	Node *n;
	CPoint _position;
};

