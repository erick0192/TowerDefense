#pragma once
#include "tower.h"
class TowerDecorator :
	public Tower
{
public:
	TowerDecorator(void);
	~TowerDecorator(void);

public:
	TowerDecorator(int level);
	TowerDecorator(Tower *decoratedTower);
		
	virtual void attack(Critter* c) = 0;
	virtual void purchase() = 0;
	virtual void refundMoney() = 0;
	
	virtual void setCost(int cost);
	virtual void setRefund(int refund);
	virtual void setRange(int range);
	virtual void setPower(int power);
	virtual void setRateOfFire(int rateOfFire);
	virtual int getCost();
	virtual int getRefund();
	virtual int getRange();
	virtual int getPower();
	virtual int getRateOfFire();

protected:
	Tower *decoratedTower;
};

