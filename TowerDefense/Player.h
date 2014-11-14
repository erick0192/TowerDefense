#pragma once

// Player document

class Player : public CDocument
{
	DECLARE_DYNCREATE(Player)

public:
	Player();
	Player(int moneyAmount);
	virtual ~Player();
	void setMoneyAmount(int amount);
	int getMoneyAmount();

#ifndef _WIN32_WCE
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

private:
	int _moneyAmount;

protected:
	virtual BOOL OnNewDocument();

	DECLARE_MESSAGE_MAP()
};
