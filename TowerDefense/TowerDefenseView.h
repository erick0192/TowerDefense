
// TowerDefenseView.h : interface of the CTowerDefenseView class
//

#pragma once


class CTowerDefenseView : public CView
{
protected: // create from serialization only
	CTowerDefenseView();
	DECLARE_DYNCREATE(CTowerDefenseView)

// Attributes
public:
	CTowerDefenseDoc* GetDocument() const;

// Operations
	//<Team defined functions>
public:
	char towerType;
	void clearSuggestion(CPoint p1);
	void clearInitSuggestions();
	void setSuggestions(CPoint* sU, CPoint* sD, CPoint* sL, CPoint* sR, CPoint p1);
	void drawSuggestion(CPoint p1);
	bool validateMap();
	void DrawGrid();
	void DisplayCritter(int x, int y);
	bool positioningTower;
	void ClearGrid();
	void RedrawGame();
	//</Team defined functions>

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CTowerDefenseView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClicked_12x6();
	afx_msg void OnBnClicked_10x4();
	afx_msg void OnBnClicked_Submit();
	afx_msg void OnBnClicked_BeginGame();
	afx_msg void OnBnClicked_BuyTowerA();
	afx_msg void OnBnClicked_UpgradeA();
	afx_msg void OnBnClicked_TowerB();
	afx_msg void OnBnClicked_UpgradeB();
	afx_msg void OnBnClicked_TowerC();
	afx_msg void OnBnClicked_UpgradeC();
};

#ifndef _DEBUG  // debug version in TowerDefenseView.cpp
inline CTowerDefenseDoc* CTowerDefenseView::GetDocument() const
   { return reinterpret_cast<CTowerDefenseDoc*>(m_pDocument); }
#endif

