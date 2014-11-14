// Tower.cpp : implementation file
//

#include "stdafx.h"
#include "TowerDefense.h"
#include "Tower.h"


// Tower

IMPLEMENT_DYNCREATE(Tower, CDocument)

Tower::Tower()
{
}

Tower::Tower(int level)
{
	_cost = 100 * level;
	_refund = _cost - 30 * level;
	_range = level * 5 + 10;
	_rateOfFire = 0 + level;
	_power = 0 + level;
//	positioningTower = false;
}

Tower::~Tower()
{
}

void Tower::purchase()
{
	// deduct the cost from the player's amount of money
	int currentMoneyAmount = player->getMoneyAmount() - _cost;

	// set as the current amount
	player->setMoneyAmount(currentMoneyAmount);
}

void Tower::refundMoney()
{
	// increase the amount of the player's money by the tower's refund value
	int currentMoneyAmount = player->getMoneyAmount() + _refund;

	// set as the current amount
	player->setMoneyAmount(currentMoneyAmount);
}

void Tower::setCost(int cost)
{
	_cost = cost;
}

void Tower::setRefund(int refund)
{
	_refund = refund;
}

void Tower::setRange(int range)
{
	_range = range;
}

void Tower::setPower(int power)
{
	_power = power;
}

void Tower::setRateOfFire(int rateOfFire)
{
	_rateOfFire = rateOfFire;
}

int Tower::getCost()
{
	return _cost;
}

int Tower::getRefund()
{
	return _refund;
}

int Tower::getRange()
{
	return _range;
}

int Tower::getPower()
{
	return _power;
}

int Tower::getRateOfFire()
{
	return _rateOfFire;
}


BOOL Tower::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}


BEGIN_MESSAGE_MAP(Tower, CDocument)
END_MESSAGE_MAP()


// Tower diagnostics

#ifdef _DEBUG
void Tower::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void Tower::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// Tower serialization

void Tower::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}
#endif


// Tower commands
