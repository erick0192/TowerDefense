
// TowerDefenseDoc.cpp : implementation of the CMapDoc class
//
#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TowerDefense.h"
#endif

#include "TowerDefenseDoc.h"
#include "TowerDefenseView.h"
#include "LinkedList.h"
#include <propkey.h>

#include "Critter.h"
#include "CritterGroup.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMapDoc

IMPLEMENT_DYNCREATE(CMapDoc, CDocument)

BEGIN_MESSAGE_MAP(CMapDoc, CDocument)
END_MESSAGE_MAP()
/*
	/////<Erick Variables>/////
	CBrush tBrush(RGB(0, 0, 255));
	CBrush sBrush(RGB(0, 255, 0));
	CBrush pBrush(RGB(255, 0, 0));

	int width, length;	//width and length of grid
	bool** grid;		//Multidimensional dynamically allocated array - true=path cell / false=tower cell
	bool pathSetUpStage = true;
	int lastX, lastY;	//lastX and lastY clicked
	bool first = true;	
	bool canDraw = true;
/////</Erick Variables>/////

	*/


// CMapDoc construction/destruction

CMapDoc::CMapDoc()
{
	// TODO: add one-time construction code here
	pathSetUpStage = true;
	first = true;	
	canDraw = true;
//	path = LinkedList();
}

void CMapDoc::MoveCritter()
{
	int sizeEX = 1;			// size example
	int levelEX = 2;		// level example
	
	CritterGroup cg;
	cg.generateCritters(sizeEX, levelEX);
	critters = cg.getCritters();

	Node *n = path.head;

	CPoint p(0, n->y);
	critters[0]->setPosition(p);
	
	int critterX = static_cast<int>(critters[0]->getPosition().x);
	int critterY = static_cast<int>(critters[0]->getPosition().y);

	POSITION pos = GetFirstViewPosition(); 
	CMapView* pFirstView = (CMapView*)GetNextView(pos);
	 

	while(n != NULL){
		if((critterX == n->x)&&(critterY == n->y))
			n = n->next;
		else if (critterX == n->x)
			if(n->y > critterY)
				critterY++;
			else
				critterY--;
		else
			if(n->x > critterX)
				critterX++;
			else
				critterX--;

		pFirstView->DisplayCritter(critterX, critterY);
	}
}

/*
void CMapDoc::MoveCritter()
{
	critterY = 340;

	POSITION pos = GetFirstViewPosition(); 
	CMapView* pFirstView = (CMapView*)GetNextView(pos);
	 

	for ( critterX = 0; critterX < ((width+1)*100); critterX++)
		pFirstView->DisplayCritter();

}
*/

CMapDoc::~CMapDoc()
{
}

BOOL CMapDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CMapDoc serialization

void CMapDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		CPoint p(length,width);
		ar << p;
		for (int i = 0; i <= width ; i ++)
			for (int j = 0; j <= length; j ++)
				if(grid[j][i])
					ar << 1;
				else
					ar << 0;
	}	
	else
	{
		CPoint p;
		ar >> p;
		length = p.x;
		width = p.y;

		grid = new bool*[length + 1];
		for (int i = 0; i <= length; i++)
			grid[i] = new bool[width + 1];	
		int x;
		for (int i = 0; i <= width; i++)
			for (int j = 0; j <= length; j++)
			{
				ar >> x;
				if(x==1)
					grid[j][i] = true;
				else
					grid[j][i] = false;
			}

		POSITION pos = GetFirstViewPosition(); 
		CMapView* pFirstView = (CMapView*)GetNextView(pos);
		pFirstView->ClearGrid();
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CMapDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CMapDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMapDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMapDoc diagnostics

#ifdef _DEBUG
void CMapDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMapDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG





// CMapDoc commands
