// Player.cpp : implementation file
//

#include "stdafx.h"
#include "TowerDefense.h"
#include "Player.h"


// Player

IMPLEMENT_DYNCREATE(Player, CDocument)

Player::Player()
{
	// default: $100
	_moneyAmount = 100;
}

Player::Player(int moneyAmount)
{
	_moneyAmount = moneyAmount;
}

Player::~Player()
{
}

void Player::setMoneyAmount(int moneyAmount)
{
	_moneyAmount = moneyAmount;
}

int Player::getMoneyAmount()
{
	return _moneyAmount;
}

BOOL Player::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}


BEGIN_MESSAGE_MAP(Player, CDocument)
END_MESSAGE_MAP()


// Player diagnostics

#ifdef _DEBUG
void Player::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void Player::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// Player serialization

void Player::Serialize(CArchive& ar)
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


// Player commands
