// CritterView.cpp : implementation file
//

#include "stdafx.h"
#include "TowerDefense.h"
#include "CritterView.h"
#include "Critter.h"

// CritterView

IMPLEMENT_DYNCREATE(CritterView, CView)

CritterView::CritterView()
{

}

CritterView::CritterView(Critter* c)
{
	critter = c;
	critter->AddView(this);
}


CritterView::~CritterView()
{
	critter->RemoveView(this);
}

BEGIN_MESSAGE_MAP(CritterView, CView)
END_MESSAGE_MAP()

void CritterView::OnUpdate()
{
	displayCritters();
}

void CritterView::displayCritters()
{
// TO DO
}

// CritterView drawing

void CritterView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}


// CritterView diagnostics

#ifdef _DEBUG
void CritterView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CritterView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CritterView message handlers
