#pragma once

//  <added pragmas>
#include "Strategy.h"
#include "Critter.h"
#include <vector>
using namespace std;
//  </added pragmas>

class Tower
{
public:
	Tower(void);
	~Tower(void);
public:
	Tower(int level);
	Tower(int x, int y, int level);
	Tower(Strategy* initStrategy);

	void setX(int x);
	void setY(int y);
	int getX();
	int getY();

	virtual void attack(Critter* c) = 0;
	virtual void purchase() = 0;
	virtual void refundMoney() = 0;

	virtual void setCost(int cost) = 0;
	virtual void setRefund(int refund) = 0;
	virtual void setRange(int range) = 0;
	virtual void setPower(int power) = 0;
	virtual void setRateOfFire(int rateOfFire) = 0;
	virtual int getCost() = 0;
	virtual int getRefund() = 0;
	virtual int getRange() = 0;
	virtual int getPower() = 0;
	virtual int getRateOfFire() = 0;

	virtual void setStrategy(Strategy* newStrategy);
	virtual int executeStrategy(vector<Critter*> critters);

protected:
	int x, y;
	Strategy* strategy;
	int _cost;
	int _refund;
	int _range;
	int _power;
	int _rateOfFire;
	bool firstAttack;
	clock_t lastAttackTime;
	clock_t currentTime;
};

