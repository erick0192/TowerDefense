
// TowerDefenseDoc.cpp : implementation of the CTowerDefenseDoc class
//
#include "Windows.h"
#include "afxwin.h"

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TowerDefense.h"
#endif

#include "TowerDefenseDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


//	<added pragmas>
#include "CritterGroup.h"
#include "TowerA.h"
//	<added pragmas>

// CTowerDefenseDoc

IMPLEMENT_DYNCREATE(CTowerDefenseDoc, CDocument)

BEGIN_MESSAGE_MAP(CTowerDefenseDoc, CDocument)
END_MESSAGE_MAP()


// CTowerDefenseDoc construction/destruction

CTowerDefenseDoc::CTowerDefenseDoc()
{
	critterGroup = new CritterGroup();
	pathSetUpStage = true;
	first = true;	
	canDraw = true;
	Gaming = false;
	numberOfCritters = 5;
	level = 1;
}

CTowerDefenseDoc::~CTowerDefenseDoc()
{
}

BOOL CTowerDefenseDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

void CTowerDefenseDoc::GameOn()
{

	POSITION pos = GetFirstViewPosition(); 
	CTowerDefenseView* pFirstView = (CTowerDefenseView*)GetNextView(pos);

	critterGroup->addStartingNode(path.head);
	critterGroup->generateCritters(numberOfCritters, level);
	critters = critterGroup->getCritters();

	t1 = clock();
	int critterQueueIndex = 0;

//	pFirstView->DisplayCritter(100,100);

	while(!critterGroup->areAllDead())
	{
		t2 = clock();
		
		if( ( (t2 - t1) >= critterDelay)&&(critterQueueIndex < numberOfCritters) )
		{
			critters[critterQueueIndex]->releaseCritter();
			critterQueueIndex++;
			t1 = t2;
		}

		pFirstView->RedrawGame();


		for (int i = 0; i < critters.size(); i++)
		{
			if(critters[i]->move())
				pFirstView->DisplayCritter(critters[i]->getPosition().x, critters[i]->getPosition().y);
		}
		for (int i = 0; i < towers.size(); i++)
		{
			int position = towers[i]->executeStrategy(critters);
			if(position>1)
				towers[i]->attack(critters[position]);
		}

		// Displays the hitpoints of the critters
		
		SetDlgItemText(m_hWndHost, IDC_EDIT1, _T("hitpoints1"));
		SetDlgItemText(m_hWndHost, IDC_EDIT2, _T("hitpoints1"));
		SetDlgItemText(m_hWndHost, IDC_EDIT3, _T("hitpoints1"));
		SetDlgItemText(m_hWndHost, IDC_EDIT4, _T("hitpoints1"));
		SetDlgItemText(m_hWndHost, IDC_EDIT5, _T("hitpoints1"));
		
	}

}

void CTowerDefenseDoc::CallDisplayCritter(int x, int y)
{
	POSITION pos = GetFirstViewPosition(); 
	CTowerDefenseView* pFirstView = (CTowerDefenseView*)GetNextView(pos);
	pFirstView->DisplayCritter(x,y);
}

// CTowerDefenseDoc serialization

void CTowerDefenseDoc::Serialize(CArchive& ar)
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
		CTowerDefenseView* pFirstView = (CTowerDefenseView*)GetNextView(pos);
		pFirstView->ClearGrid();
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CTowerDefenseDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CTowerDefenseDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CTowerDefenseDoc::SetSearchContent(const CString& value)
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

// CTowerDefenseDoc diagnostics

#ifdef _DEBUG
void CTowerDefenseDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTowerDefenseDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CTowerDefenseDoc commands
