// TowerGroup.cpp : implementation file
//

#include "stdafx.h"
#include "TowerDefense.h"
#include "TowerGroup.h"


// TowerGroup

IMPLEMENT_DYNCREATE(TowerGroup, CDocument)

TowerGroup::TowerGroup()
{
}

TowerGroup::~TowerGroup()
{
	for (int i = 0; i < _towers.size(); i++)
	{
		delete _towers[i];
	}
}

void TowerGroup::generateTowers(int size, int level)
{
	for (int i = 0; i < size; i++)
	{
		Tower *tower = new Tower(level);
		_towers.push_back(tower);
	}
}

void TowerGroup::addTowerViews(TowerView *view)
{
	for (int i = 0; i < _towers.size(); i++)
	{
		_towers[i]->AddView(view);
	}
}

BOOL TowerGroup::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}


BEGIN_MESSAGE_MAP(TowerGroup, CDocument)
END_MESSAGE_MAP()


// TowerGroup diagnostics

#ifdef _DEBUG
void TowerGroup::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void TowerGroup::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// TowerGroup serialization

void TowerGroup::Serialize(CArchive& ar)
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


// TowerGroup commands
