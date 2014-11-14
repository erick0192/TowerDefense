#pragma once

#include "Critter.h"
#include "CritterView.h"
#include <vector>
// CritterGroup document

using namespace std;

class CritterGroup : public CDocument
{
	DECLARE_DYNCREATE(CritterGroup)

public:
	CritterGroup();
	virtual ~CritterGroup();

	void generateCritters(int size, int level);
	bool areAllDead();
	void addCritterViews(CritterView *view);
	vector<Critter*> getCritters();
	//bool areAllExited();
	//void action(Map &map);


private:
	vector<Critter*> _critters;
	int _currentIndexOfCritter;

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
