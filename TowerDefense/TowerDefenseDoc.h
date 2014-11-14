
// TowerDefenseDoc.h : interface of the CMapDoc class
//


#pragma once
#include "LinkedList.h"
#include "Critter.h"
#include <vector>

using namespace std;

class CMapDoc : public CDocument
{
protected: // create from serialization only
	CMapDoc();
	DECLARE_DYNCREATE(CMapDoc)

// Attributes
public:
	int variable;
	/////<Erick Variables>/////
	int width, length;	//width and length of grid
	bool** grid;		//Multidimensional dynamically allocated array - true=path cell / false=tower cell
	bool pathSetUpStage;
	int lastX, lastY;	//lastX and lastY clicked
	bool first;	
	bool canDraw;
	//int critterX;
	//int critterY;
	vector<Critter*> critters;
	void MoveCritter();
	LinkedList path;

/////</Erick Variables>/////

// Operations
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
	virtual ~CMapDoc();
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
