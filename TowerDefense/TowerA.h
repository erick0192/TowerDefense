#pragma once
#include "tower.h"
//  <added pragmas
//  </added pragmas>
class TowerA :
	public Tower
{
public:
	TowerA(void);
	~TowerA(void);
public:
	TowerA(int x, int y, int level);
	
	void attack(Critter* c);
	void purchase();
	void refundMoney();
	int executeStrategy(vector<Critter*> critters);
	void setStrategy(Strategy* newStrategy);

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
};

