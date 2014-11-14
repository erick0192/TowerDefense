// TowerView.cpp : implementation file
//

#include "stdafx.h"
#include "TowerDefense.h"
#include "TowerView.h"
#include "Tower.h"

// TowerView

IMPLEMENT_DYNCREATE(TowerView, CView)

TowerView::TowerView()
{
	positioningTower = false;
}

TowerView::TowerView(Tower* t)
{
	tower = t;
	tower->AddView(this);
}

TowerView::~TowerView()
{
	tower->RemoveView(this);
}

BEGIN_MESSAGE_MAP(TowerView, CView)
//	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON4, &TowerView::OnBnClicked_TowerA)
	ON_BN_CLICKED(IDC_BUTTON5, &TowerView::OnBnClicked_TowerB)
END_MESSAGE_MAP()

void TowerView::OnUpdate()
{
	displayTowers();
}

void TowerView::displayTowers()
{

}

// TowerView drawing

void TowerView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here

	CBrush brush(RGB(156, 189, 255));	//
	
	pDC->SelectObject(brush);

	int x = 40;
	int y = 40; 
	CPoint p1(x, y);			//upper left hans side
	CPoint p2(x + 20, y + 20);	//lower right hand side
	CRect r(p1, p2);
	pDC->Rectangle(r);			//Draw
}


// TowerView diagnostics

#ifdef _DEBUG
void TowerView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void TowerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// TowerView message handlers


void TowerView::OnBnClicked_TowerA()
{
	MessageBox(_T("Help, Something went wrong."), _T("Error"), 
      MB_ICONERROR | MB_OK);
/*	Tower* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
		*/
	positioningTower = true;
}
/*
void TowerView::OnLButtonDown(UINT /* nFlags*, CPoint point)
{
	/*
	Tower* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
*
	if(positioningTower){
		int x = point.x - (point.x % 100), y = point.y - (point.y % 100);

		CBrush pBrush(RGB(255, 255, 255));
		CDC *pDC = GetDC();
		CPoint p1(x+20, y+20), p2(x + 80, y + 80);
		CRect r(p1, p2);
		pDC->Rectangle(r);
		positioningTower = false;
	}


	}*/

void TowerView::OnBnClicked_TowerB()
{
	MessageBox(_T("Help, Something went wrong."), _T("Error"), 
      MB_ICONERROR | MB_OK);

	positioningTower = true;
}
