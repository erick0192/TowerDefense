#pragma once

#include "Player.h"

using namespace std;
// Tower document

class Tower : public CDocument
{
	DECLARE_DYNCREATE(Tower)

public:
	Tower();
	Tower::Tower(int level);
	virtual ~Tower();
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
//	bool positioningTower;
	Player* player;

private:
	int _range;
	int _power;
	int _rateOfFire;
	int _cost;
	int _refund;
	CPoint position;

#ifndef _WIN32_WCE
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual BOOL OnNewDocument();

	DECLARE_MESSAGE_MAP()
};
