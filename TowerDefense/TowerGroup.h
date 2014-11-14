#pragma once

#include "Tower.h"
#include "TowerView.h"
#include <vector>
// TowerGroup document

using namespace std;

class TowerGroup : public CDocument
{
	DECLARE_DYNCREATE(TowerGroup)

public:
	TowerGroup();
	virtual ~TowerGroup();

	void generateTowers(int size, int level);
	void addTowerViews(TowerView *view);


private:
	vector<Tower*> _towers;
	int _currentIndexOfTower;

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
