
// TowerDefenseDoc.h : interface of the CTowerDefenseDoc class
//
#pragma once
//	<added pragmas>
#include "LinkedList.h"
#include <vector>
class Tower;
class CritterGroup;
class Critter;
//#include "CritterGroup.h"
//#include "Tower.h"
//	<added pragmas>
class CTowerDefenseDoc : public CDocument
{
protected: // create from serialization only
	CTowerDefenseDoc();
	DECLARE_DYNCREATE(CTowerDefenseDoc)

// Attributes
public:
	int variable;
	/////<Team Variables>/////
	int width, length;	//width and length of grid
	bool** grid;		//Multidimensional dynamically allocated array - true=path cell / false=tower cell
	bool pathSetUpStage;
	int lastX, lastY;	//lastX and lastY clicked
	bool first;	
	bool canDraw;
	bool Gaming;


	void GameOn();
	void CallDisplayCritter(int x, int y);
	LinkedList path;
	CritterGroup* critterGroup;
	std::vector<Critter*> critters;
	std::vector<Tower*> towers;
	int numberOfCritters;			// size example
	int level;						// level example
	clock_t t1, t2;
	static const long critterDelay = 3000;
	/////</Team Variables>/////

public:
// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CTowerDefenseDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};