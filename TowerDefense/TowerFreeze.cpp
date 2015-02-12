#include "stdafx.h"
#include "TowerFreeze.h"


TowerFreeze::TowerFreeze(void)
{
}


TowerFreeze::~TowerFreeze(void)
{
}

TowerFreeze::TowerFreeze(int level)
{
	setCost(100 * level);
	setRefund(getCost() - 30 * level);
	setRange(level * 5 + 10);
	setRateOfFire(level);
	setPower(level);
}

TowerFreeze::TowerFreeze(Tower *decoratedTower)
{
	this->decoratedTower = decoratedTower;
}


void TowerFreeze::attack(Critter* c)
{/*
	//TODO: add attack code
	Critter *target = findTarget();
	displayAnimation();
	target->gotBurned(TowerFreeze::getPower());
	target->takeDamage(TowerFreeze::getPower());
*/
}

void TowerFreeze::purchase()
{/*
	int currentMoneyAmount = player->getMoneyAmount() - TowerFreeze::getCost();
	player->setMoneyAmount(currentMoneyAmount);
*/
}

void TowerFreeze::refundMoney()
{/*
	int currentMoneyAmount = player->getMoneyAmount() + TowerFreeze::getRefund();
	player->setMoneyAmount(currentMoneyAmount);
*/	
}


void TowerFreeze::setCost(int cost)
{
	TowerDecorator::setCost(cost - EXTRA_COST);
}

void TowerFreeze::setRefund(int refund)
{
	TowerDecorator::setRefund(refund - EXTRA_REFUND);
}

void TowerFreeze::setRange(int range)
{
	TowerDecorator::setRange(range - EXTRA_RANGE);
}

void TowerFreeze::setPower(int power)
{
	TowerDecorator::setPower(power - EXTRA_POWER);
}

void TowerFreeze::setRateOfFire(int rateOfFire)
{
	TowerDecorator::setRateOfFire(rateOfFire - EXTRA_RATEOFFIRE);
}

int TowerFreeze::getCost()
{
	return TowerDecorator::getCost() + EXTRA_COST;
}

int TowerFreeze::getRefund()
{
	return TowerDecorator::getRefund() + EXTRA_REFUND;
}

int TowerFreeze::getRange()
{
	return TowerDecorator::getRange() + EXTRA_RANGE;
}

int TowerFreeze::getPower()
{
	return TowerDecorator::getPower() + EXTRA_POWER;
}

int TowerFreeze::getRateOfFire()
{
	return TowerDecorator::getRateOfFire() + EXTRA_RATEOFFIRE;
}