#include "stdafx.h"
#include "TowerBurn.h"


TowerBurn::TowerBurn(void)
{
}


TowerBurn::~TowerBurn(void)
{
}


TowerBurn::TowerBurn(int level)
{
	setCost(100 * level);
	setRefund(getCost() - 30 * level);
	setRange(level * 5 + 10);
	setRateOfFire(level);
	setPower(level);
}

TowerBurn::TowerBurn(Tower *decoratedTower)
{
	this->decoratedTower = decoratedTower;
}


void TowerBurn::attack(Critter* c)
{/*
	//TODO: add attack code
	Critter *target = findTarget();
	displayAnimation();
	target->gotBurned(TowerBurn::getPower());
	target->takeDamage(TowerBurn::getPower());
*/
}

void TowerBurn::purchase()
{/*
	int currentMoneyAmount = player->getMoneyAmount() - TowerBurn::getCost();
	player->setMoneyAmount(currentMoneyAmount);
*/
}

void TowerBurn::refundMoney()
{/*
	int currentMoneyAmount = player->getMoneyAmount() + TowerBurn::getRefund();
	player->setMoneyAmount(currentMoneyAmount);
*/	
}


void TowerBurn::setCost(int cost)
{
	TowerDecorator::setCost(cost - EXTRA_COST);
}

void TowerBurn::setRefund(int refund)
{
	TowerDecorator::setRefund(refund - EXTRA_REFUND);
}

void TowerBurn::setRange(int range)
{
	TowerDecorator::setRange(range - EXTRA_RANGE);
}

void TowerBurn::setPower(int power)
{
	TowerDecorator::setPower(power - EXTRA_POWER);
}

void TowerBurn::setRateOfFire(int rateOfFire)
{
	TowerDecorator::setRateOfFire(rateOfFire - EXTRA_RATEOFFIRE);
}

int TowerBurn::getCost()
{
	return TowerDecorator::getCost() + EXTRA_COST;
}

int TowerBurn::getRefund()
{
	return TowerDecorator::getRefund() + EXTRA_REFUND;
}

int TowerBurn::getRange()
{
	return TowerDecorator::getRange() + EXTRA_RANGE;
}

int TowerBurn::getPower()
{
	return TowerDecorator::getPower() + EXTRA_POWER;
}

int TowerBurn::getRateOfFire()
{
	return TowerDecorator::getRateOfFire() + EXTRA_RATEOFFIRE;
}