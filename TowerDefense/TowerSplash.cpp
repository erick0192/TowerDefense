#include "stdafx.h"
#include "TowerSplash.h"


TowerSplash::TowerSplash(void)
{
}


TowerSplash::~TowerSplash(void)
{
}

TowerSplash::TowerSplash(int level)
{
	setCost(100 * level);
	setRefund(getCost() - 30 * level);
	setRange(level * 5 + 10);
	setRateOfFire(level);
	setPower(level);
}

TowerSplash::TowerSplash(Tower *decoratedTower)
{
	this->decoratedTower = decoratedTower;
}


void TowerSplash::attack(Critter* c)
{/*
	//TODO: add attack code
	Critter *target = findTarget();
	displayAnimation();
	target->gotBurned(TowerSplash::getPower());
	target->takeDamage(TowerSplash::getPower());
*/
}

void TowerSplash::purchase()
{/*
	int currentMoneyAmount = player->getMoneyAmount() - TowerSplash::getCost();
	player->setMoneyAmount(currentMoneyAmount);
*/
}

void TowerSplash::refundMoney()
{/*
	int currentMoneyAmount = player->getMoneyAmount() + TowerSplash::getRefund();
	player->setMoneyAmount(currentMoneyAmount);
*/
}


void TowerSplash::setCost(int cost)
{
	TowerDecorator::setCost(cost - EXTRA_COST);
}

void TowerSplash::setRefund(int refund)
{
	TowerDecorator::setRefund(refund - EXTRA_REFUND);
}

void TowerSplash::setRange(int range)
{
	TowerDecorator::setRange(range - EXTRA_RANGE);
}

void TowerSplash::setPower(int power)
{
	TowerDecorator::setPower(power - EXTRA_POWER);
}

void TowerSplash::setRateOfFire(int rateOfFire)
{
	TowerDecorator::setRateOfFire(rateOfFire - EXTRA_RATEOFFIRE);
}

int TowerSplash::getCost()
{
	return TowerDecorator::getCost() + EXTRA_COST;
}

int TowerSplash::getRefund()
{
	return TowerDecorator::getRefund() + EXTRA_REFUND;
}

int TowerSplash::getRange()
{
	return TowerDecorator::getRange() + EXTRA_RANGE;
}

int TowerSplash::getPower()
{
	return TowerDecorator::getPower() + EXTRA_POWER;
}

int TowerSplash::getRateOfFire()
{
	return TowerDecorator::getRateOfFire() + EXTRA_RATEOFFIRE;
}