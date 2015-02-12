#include "stdafx.h"
#include "TowerDecorator.h"


TowerDecorator::TowerDecorator(void)
{
}


TowerDecorator::~TowerDecorator(void)
{
}


TowerDecorator::TowerDecorator(int level)
{
}


TowerDecorator::TowerDecorator(Tower *decoratedTower)
{
	this->decoratedTower = decoratedTower;
}


void TowerDecorator::attack(Critter* c)
{
}


void TowerDecorator::purchase()
{/*
	// deduct the cost from the player's amount of money
	int currentMoneyAmount = player->getMoneyAmount() - _cost;

	// set as the current amount
	player->setMoneyAmount(currentMoneyAmount);
*/
//	cout << "TowerDecorator purchase\n";
}


void TowerDecorator::refundMoney()
{/*
	// increase the amount of the player's money by the TowerDecorator's refund value
	int currentMoneyAmount = player->getMoneyAmount() + _refund;

	// set as the current amount
	player->setMoneyAmount(currentMoneyAmount);
*/
//	cout << "TowerDecorator refundMoney\n";
}


void TowerDecorator::setCost(int cost)
{
	decoratedTower->setCost(cost);
}


void TowerDecorator::setRefund(int refund)
{
	decoratedTower->setRefund(refund);
}

void TowerDecorator::setRange(int range)
{
	decoratedTower->setRange(range);
}


void TowerDecorator::setPower(int power)
{
	decoratedTower->setPower(power);
}


void TowerDecorator::setRateOfFire(int rateOfFire)
{
	decoratedTower->setRateOfFire(rateOfFire);
}


int TowerDecorator::getCost()
{
	return decoratedTower->getCost();
}


int TowerDecorator::getRefund()
{
	return decoratedTower->getRefund();
}


int TowerDecorator::getRange()
{
	return decoratedTower->getRange();
}


int TowerDecorator::getPower()
{
	return decoratedTower->getPower();
}


int TowerDecorator::getRateOfFire()
{
	return decoratedTower->getRateOfFire();
}