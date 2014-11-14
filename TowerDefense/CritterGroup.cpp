// CritterGroup.cpp : implementation file
//

#include "stdafx.h"
#include "TowerDefense.h"
#include "CritterGroup.h"


// CritterGroup

IMPLEMENT_DYNCREATE(CritterGroup, CDocument)

CritterGroup::CritterGroup()
{
}

CritterGroup::~CritterGroup()
{
	for (int i = 0; i < _critters.size(); i++)
	{
		delete _critters[i];
	}
}

void CritterGroup::generateCritters(int size, int level)
{
	for (int i = 0; i < size; i++)
	{
		Critter *critter = new Critter(level);
		_critters.push_back(critter);
	}
}

bool CritterGroup::areAllDead()
{
	for (int i = 0; i < _critters.size(); i++)
	{
		// if at least ONE critter is not dead, return false
		if (_critters[i]->isDead() == false)
			return false;
	}

	return true;
}

void CritterGroup::addCritterViews(CritterView *view)
{
	for (int i = 0; i < _critters.size(); i++)
	{
		_critters[i]->AddView(view);
	}
}

vector<Critter*> CritterGroup::getCritters()
{
	return _critters;
}

BOOL CritterGroup::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}


BEGIN_MESSAGE_MAP(CritterGroup, CDocument)
END_MESSAGE_MAP()


// CritterGroup diagnostics

#ifdef _DEBUG
void CritterGroup::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void CritterGroup::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// CritterGroup serialization

void CritterGroup::Serialize(CArchive& ar)
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


// CritterGroup commands
