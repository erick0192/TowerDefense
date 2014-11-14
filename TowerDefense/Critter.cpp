// Critter.cpp : implementation file
//

#include "stdafx.h"
#include "TowerDefense.h"
#include "Critter.h"
#include "CritterView.h"


// Critter

IMPLEMENT_DYNCREATE(Critter, CDocument)

Critter::Critter() {}

Critter::Critter(int level)
{
	_level = level;
	_reward = level * 25;
	_strength = level + 10;
	_speed = level + 0;
	_position = 0;
	_hitpoints = level * 50;
	_dead = false;
}

Critter::~Critter() {}

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

	// Notify()
	UpdateAllViews(NULL);
}

/*************************************************
void Critter::move(int position)
{
	// TO DO
}
*************************************************/



BOOL Critter::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

BEGIN_MESSAGE_MAP(Critter, CDocument)
END_MESSAGE_MAP()


// Critter diagnostics

#ifdef _DEBUG
void Critter::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void Critter::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// Critter serialization

void Critter::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}
#endif


// Critter commands
