#include "stdafx.h"
#include "TowerA.h"
#include "CheckNearTower.h"

TowerA::TowerA(void)
{
}


TowerA::~TowerA(void)
{
}

TowerA::TowerA(int x, int y, int level)
{
	setCost(100 * level);
	setRefund(getCost() - 30 * level);
	setRange(level * 5 + 10);
	setRateOfFire(level*1000);
	setPower(level);
	this->x = x;
	this->y = y;
	currentTime = clock();
	lastAttackTime = currentTime;
	Strategy* a = new CheckNearTower(); 
	setStrategy(a);
}

void TowerA::attack(Critter* c)
{/*
	//TODO: add attack code
	Critter *target = findTarget();
	displayAnimation();
	target->takeDamage(TowerBurn::getPower());
*/
	currentTime = clock();
	if((currentTime - lastAttackTime) >= _rateOfFire)
	{
		c->isAttacked(_power);
/*		if(c->isDead())
			delete c;
			*/
		lastAttackTime = clock();
	}

}

void TowerA::purchase()
{/*
	// deduct the cost from the player's amount of money
	int currentMoneyAmount = player->getMoneyAmount() - _cost;

	// set as the current amount
	player->setMoneyAmount(currentMoneyAmount);
*/
}

void TowerA::refundMoney()
{/*
	// increase the amount of the player's money by the TowerA's refund value
	int currentMoneyAmount = player->getMoneyAmount() + _refund;

	// set as the current amount
	player->setMoneyAmount(currentMoneyAmount);
*/
}

void TowerA::setStrategy(Strategy* newStrategy){
	Tower::setStrategy(newStrategy);
}


int TowerA::executeStrategy(vector<Critter*> critters)
{
	return Tower::executeStrategy(critters);
}


void TowerA::setCost(int cost)
{
	_cost = cost;
}

void TowerA::setRefund(int refund)
{
	_refund = refund;
}

void TowerA::setRange(int range)
{
	_range = range;
}

void TowerA::setPower(int power)
{
	_power = power;
}

void TowerA::setRateOfFire(int rateOfFire)
{
	_rateOfFire = rateOfFire;
}

int TowerA::getCost()
{
	return _cost;
}

int TowerA::getRefund()
{
	return _refund;
}

int TowerA::getRange()
{
	return _range;
}

int TowerA::getPower()
{
	return _power;
}

int TowerA::getRateOfFire()
{
	return _rateOfFire;
}
