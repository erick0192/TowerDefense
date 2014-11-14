#pragma once

// Critter document

class Critter : public CDocument
{
	DECLARE_DYNCREATE(Critter)

public:
	Critter();
	Critter(int level);
	~Critter();

	void setReward(int reward);
	void setHitpoints(int hitpoints);
	void setStrength(int strength);
	void setLevel(int level);
	void setSpeed(int speed);
	void setDead(bool dead);
	void setPosition(CPoint position);

	int getReward();
	int getHitpoints();
	int getStrength();
	int getLevel();
	int getSpeed();

	bool isDead();
	CPoint getPosition();
    void isAttacked(int towerDamage);
//  void move(int position);

private:
	int _reward;
	int _hitpoints;
	int _strength;
	int _speed;
	int _level;
	bool _dead;
	CPoint _position;

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
