
// TowerDefenseView.h : interface of the CMapView class
//

#pragma once


class CMapView : public CView
{
protected: // create from serialization only
	CMapView();
	DECLARE_DYNCREATE(CMapView)

// Attributes
public:
	CMapDoc* GetDocument() const;

// Operations
public:
	//<Erick defined functions>
public:
	void clearSuggestion(CPoint p1);
	void clearInitSuggestions();
	void setSuggestions(CPoint* sU, CPoint* sD, CPoint* sL, CPoint* sR, CPoint p1);
	void drawSuggestion(CPoint p1);
	bool validateMap();
	void DrawGrid();
	void DisplayCritter(int x, int y);
	bool positioningTower;
	void ClearGrid();
//	virtual CMapView* GetNextView(POSITION& rPosition) const;
	//</Erick defined functions>
	
private:
	vector<CRect*> rectangles;
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
	virtual ~CMapView();
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
	afx_msg void OnBnClicked_SubmitMap();
	afx_msg void OnBnClicked_TowerC();
};

#ifndef _DEBUG  // debug version in TowerDefenseView.cpp
inline CMapDoc* CMapView::GetDocument() const
   { return reinterpret_cast<CMapDoc*>(m_pDocument); }
#endif

