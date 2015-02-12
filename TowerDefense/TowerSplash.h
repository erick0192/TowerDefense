#pragma once
#include "towerdecorator.h"
class TowerSplash :
	public TowerDecorator
{
public:
	TowerSplash(void);
	~TowerSplash(void);
public:
	TowerSplash(int level);
	TowerSplash(Tower *decoratedCoffee);
	
	void attack(Critter* c);
	void purchase();
	void refundMoney();
	
	void setCost(int cost);
	void setRefund(int refund);
	void setRange(int range);
	void setPower(int power);
	void setRateOfFire(int rateOfFire);
	int getCost();
	int getRefund();
	int getRange();
	int getPower();
	int getRateOfFire();

private:
	static const int EXTRA_COST = 100;
	static const int EXTRA_REFUND = 100;
	static const int EXTRA_RANGE = 100;
	static const int EXTRA_POWER = 100;
	static const int EXTRA_RATEOFFIRE = 100;
};

