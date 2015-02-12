#include "stdafx.h"
#include "Critter.h"



Critter::Critter(void)
{
}


Critter::~Critter(void)
{
}


Critter::Critter(int level, Node* head)
{
	_level = level;
	_reward = level * 25;
	_strength = level + 10;
	_speed = level + 0;
	_position = 0;
	_hitpoints = level * 50;
	_dead = false;
	n = head;
	released = false;
	_position.x = 0;
	_position.y = n->y;
}


void Critter::setLevel(int level)
{
	_level = level;
}

void Critter::setReward(int reward)
{
	_reward = reward;
}

void Critter::setStrength(int strength)
{
	_strength = strength;
}

void Critter::setSpeed(int speed)
{
	_speed = speed;
}

void Critter::setHitpoints(int hitpoints)
{
	_hitpoints = hitpoints;
}

void Critter::setDead(bool dead)
{
	_dead = dead;
}

void Critter::setPosition(CPoint position)
{
	_position = position;
}

int Critter::getReward()
{
	return _reward;
}

int Critter::getHitpoints()
{
	return _hitpoints;
}

int Critter::getStrength()
{
	return _strength;
}
	
int Critter::getLevel()
{
	return _level;
}

int Critter::getSpeed()
{
	return _speed;
}
	
bool Critter::isDead()
{
	return _dead;
}

CPoint Critter::getPosition()
{
	return _position;
}

void Critter::isAttacked(int towerDamage)
{
	_hitpoints = _hitpoints - towerDamage;
}

void Critter::releaseCritter()
{
	released = true;
}

bool Critter::move()
{
	if(released)
	{
		POSITION pos = GetFirstViewPosition(); 
		CTowerDefenseView* pFirstView = (CTowerDefenseView*)GetNextView(pos);
	 
	
		if( (n != NULL)&&(!isDead()) ){
			if((_position.x == n->x)&&(_position.y == n->y))
				n = n->next;
			else if (_position.x == n->x)
				if(n->y > _position.y)
					_position.y+=_speed;
				else
					_position.y-=_speed;
			else
				if(n->x > _position.x)
					_position.x+=_speed;
				else
					_position.x-=_speed;
			return true;
	//		CTowerDefenseDoc::CallDisplayCritter((int)_position.x, (int)_position.y);
		}
		return false;
	}
	return false;
}