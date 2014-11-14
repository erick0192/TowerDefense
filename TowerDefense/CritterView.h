#pragma once

#include "Critter.h"
// CritterView view

class CritterView : public CView
{
	DECLARE_DYNCREATE(CritterView)

protected:
	CritterView();           // protected constructor used by dynamic creation
	virtual ~CritterView();

public:
	CritterView(Critter* c);
	void OnUpdate();
	void displayCritters();		// implementation TO DO in .cpp

	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

private:
	Critter* critter;

protected:
	DECLARE_MESSAGE_MAP()

};


