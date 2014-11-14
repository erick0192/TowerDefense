#pragma once

#include "Tower.h"
// TowerView view

class TowerView : public CView
{
	DECLARE_DYNCREATE(TowerView)

protected:
	TowerView();           // protected constructor used by dynamic creation
	virtual ~TowerView();

public:
	TowerView(Tower* t);
	void OnUpdate();
	void displayTowers();	
	bool positioningTower;
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

private:
	Tower* tower;

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClicked_TowerA();
//	afx_msg void OnLButtonDown(UINT /* nFlags*/, CPoint point);
	afx_msg void OnBnClicked_TowerB();
};


