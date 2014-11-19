
// TowerDefenseView.cpp : implementation of the CMapView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TowerDefense.h"
#endif

#include "TowerDefenseDoc.h"
#include "TowerDefenseView.h"
#include <string>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMapView

IMPLEMENT_DYNCREATE(CMapView, CView)

BEGIN_MESSAGE_MAP(CMapView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	//Button and click handlers
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON1, &CMapView::OnBnClicked_12x6)
	ON_BN_CLICKED(IDC_BUTTON2, &CMapView::OnBnClicked_10x4)
	ON_BN_CLICKED(IDC_BUTTON3, &CMapView::OnBnClicked_SubmitMap)
	ON_BN_CLICKED(IDC_BUTTON6, &CMapView::OnBnClicked_TowerC)
END_MESSAGE_MAP()

// CMapView construction/destruction

CMapView::CMapView()
{
	positioningTower = false;

}

CMapView::~CMapView()
{
}

BOOL CMapView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMapView drawing

void CMapView::OnDraw(CDC* /*pDC*/)
{
	CMapDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMapView printing

BOOL CMapView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}
 
void CMapView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMapView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMapView diagnostics

#ifdef _DEBUG
void CMapView::AssertValid() const
{
	CView::AssertValid();
}

void CMapView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMapDoc* CMapView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMapDoc)));
	return (CMapDoc*)m_pDocument;
}
#endif //_DEBUG

CBrush tBrush(RGB(0, 0, 255));
CBrush sBrush(RGB(0, 255, 0));
CBrush pBrush(RGB(255, 0, 0));


/////////////////////////////Erick's Functions//////////////////////////////////////////////////////////////
//function to draw the grid
void CMapView::DrawGrid()
{
		CMapDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (!pDoc)
			return;

		CDC *pDC = GetDC();

		pDC->SelectObject(tBrush);

		for (int i = 100; i <= (pDoc->width * 100); i += 100)
			for (int j = 0; j <= (pDoc->length * 100); j += 100)
			{
			CPoint p1(i, j), p2(i + 100, j + 100);
			CRect r(p1, p2);
			pDC->Rectangle(r);
			}

		pDC->SelectObject(sBrush);
		for (int j = 0; j <= (pDoc->length * 100); j += 100)
		{
			CPoint p1(0, j), p2(100, j + 100);
			CRect r(p1, p2);
			pDC->Rectangle(r);
		}

	// TODO: add draw code for native data here
}

void CMapView::ClearGrid()
{
	CMapDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;



	CDC *pDC = GetDC();
/*
	pDC->SelectObject(tBrush);
	CPoint p1(0, 0), p2(100,  100);
	CRect r(p1, p2);
	pDC->Rectangle(r);
*/
	for (int i = 0; i <= pDoc->width ; i ++)
		for (int j = 0; j <= pDoc->length; j ++)
		{
	//		pDC->SelectObject(tBrush);
			if(pDoc->grid[j][i])
				pDC->SelectObject(pBrush);
			else
				pDC->SelectObject(tBrush);
			CPoint p1(i*100, j*100), p2((i*100) + 100, (j*100) + 100);
			CRect r(p1, p2);
			pDC->Rectangle(r);
		} 
	std::string test1 = std::to_string(pDoc->length) + " " + std::to_string(pDoc->width);
	MessageBoxA(NULL, test1.c_str(), "testx", MB_OK);
}

//event handler for mouse click to store the path and display
void CMapView::OnLButtonDown(UINT /* nFlags*/, CPoint point)
{

	CMapDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (!pDoc)
			return;
	if((positioningTower)&&(!pDoc->pathSetUpStage))			//to move to TowerView later
	{       

		int x = point.x - (point.x % 100), y = point.y - (point.y % 100);
		if(pDoc->grid[y/100][x/100]){
			MessageBox(_T("Cannot place tower in a path cell"), _T("Error"), 
		  MB_ICONERROR | MB_OK);
		}
		else{
			CBrush pBrush(RGB(255, 255, 255));
			CDC *pDC = GetDC();
			CPoint p1(x+20, y+20), p2(x + 80, y + 80);
			CRect r(p1, p2);
			pDC->Rectangle(r);
			positioningTower = false;
		}
	}
	else 
	{
	CMapDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	int x = point.x - (point.x % 100), y = point.y - (point.y % 100);
	static CPoint sU, sD, sL, sR;

	bool lastisL = ((x == (pDoc->lastX - 100)) && (y == pDoc->lastY));
	bool lastisR = ((x == (pDoc->lastX + 100)) && (y == pDoc->lastY));
	bool lastisU = ((x == pDoc->lastX) && (y == (pDoc->lastY - 100)));
	bool lastisD = ((x == pDoc->lastX) && (y == (pDoc->lastY + 100)));

	if (pDoc->pathSetUpStage)
		if (!pDoc->grid[y / 100][x / 100])
			if ((x < ((pDoc->width + 1) * 100)) && (y < ((pDoc->length + 1) * 100)))
				if (((lastisL || lastisR || lastisU || lastisD) && !pDoc->first) || (pDoc->first && (x == 0)))
				{
					if (pDoc->first)
						clearInitSuggestions();
					/*			else
					{
					clearSuggestion(sU);
					clearSuggestion(sD);
					clearSuggestion(sL);
					clearSuggestion(sR);
					}
					*/
					pDoc->path.addToEnd(x+40, y+40);

					CDC *pDC = GetDC();
					pDC->SelectObject(pBrush);
					CPoint p1(x, y), p2(x + 100, y + 100);
					CRect r(p1, p2);
					pDC->Rectangle(r);
					pDoc->grid[y / 100][x / 100] = true;

					/*			setSuggestions(&sU, &sD, &sL, &sR, p1);
					drawSuggestion(sU);
					drawSuggestion(sD);
					drawSuggestion(sL);
					drawSuggestion(sR);
					*/
					pDoc->lastX = x;
					pDoc->lastY = y;
					pDoc->first = false;
				}

	}
}

//clear suggestions displayed - not used in this implementation
void CMapView::clearSuggestion(CPoint p1)
{
	CMapDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CDC *pDC = GetDC();
	pDC->SelectObject(tBrush);
	if ((!pDoc->grid[p1.y / 100][p1.x / 100]) && (p1.x <= (pDoc->width * 100)) && (p1.y <= (pDoc->length * 100)))
	{
		CPoint p2(p1.x + 100, p1.y + 100);
		CRect r(p1, p2);
		pDC->Rectangle(r);
	}
}

//clear initial yellow suggestions that show where you're allowed to click
void CMapView::clearInitSuggestions()
{
	CMapDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CDC *pDC = GetDC();
	pDC->SelectObject(tBrush);
	for (int j = 0; j <= (pDoc->length * 100); j += 100)
	{
		CPoint p1(0, j), p2(100, j + 100);
		CRect r(p1, p2);
		pDC->Rectangle(r);
	}
}

//calculate where suggestions go - not used in this implementation
void CMapView::setSuggestions(CPoint* sU, CPoint* sD, CPoint* sL, CPoint* sR, CPoint p1)
{
	sU->x = p1.x;
	sU->y = p1.y - 100;

	sD->x = p1.x;
	sD->y = p1.y + 100;

	sL->x = p1.x - 100;
	sL->y = p1.y;

	sR->x = p1.x + 100;
	sR->y = p1.y;
}

//draw suggestions - not used in this implementation
void CMapView::drawSuggestion(CPoint p1)
{
	CMapDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CDC *pDC = GetDC();
	pDC->SelectObject(sBrush);
	if ((!pDoc->grid[p1.y / 100][p1.x / 100]) && (p1.y <= (pDoc->length * 100)) && (p1.x <= (pDoc->width * 100)))
	{
		CPoint p2(p1.x + 100, p1.y + 100);
		CRect r(p1, p2);
		pDC->Rectangle(r);
	}
}

void CMapView::DisplayCritter(int x, int y)
{
	CMapDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;



	CDC *pDC = GetDC();
/*
	for (int i = 0; i <= (pDoc->width * 100); i += 100)
		for (int j = 0; j <= (pDoc->length * 100); j += 100)
		{
			CPoint p1(i, j), p2(i + 100, j + 100);
			CRect r(p1, p2);
			if(pDoc->grid[j][i])
				pDC->SelectObject(pBrush);
			else
				pDC->SelectObject(tBrush);
			pDC->Rectangle(r);
		}
*/
//	ClearGrid();
	//Clearing Grid
	for (int i = 0; i <= pDoc->width; i++)
	{
		for (int j = 0; j <= pDoc->length; j++)
		{
			if (pDoc->grid[j][i])
				pDC->SelectObject(pBrush);
			else
				pDC->SelectObject(tBrush);
			CPoint p1(i*100, j*100), p2((i*100) + 100, (j*100) + 100);
			CRect r(p1, p2);
			pDC->Rectangle(r);
		}
	}

	pDC->SelectObject(sBrush);
	CPoint p1(x, y), p2(x+20, y+20);
	CRect r(p1, p2);
	pDC->Rectangle(r);
/*
	int i = x;
	int j = y;

	for (int count = 0; count <1; count++)
	{
		pDC->SelectObject(sBrush);
		CRect *rectangle = new CRect(i, j, i+20, j+20);
		rectangles.push_back(rectangle);
//		delete rectangle;
	}

	for(int index = 0; index < rectangles.size(); index++)
	{
		pDC->Rectangle(rectangles[index]);
		rectangles[index]->MoveToXY(i, j);
	}
*/
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////

// CMapView message handlers

void CMapView::OnBnClicked_12x6()
{
	CMapDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if (pDoc->canDraw){
		pDoc->width = 11;
		pDoc->length = 5;

		pDoc->grid = new bool*[6];
		for (int i = 0; i <= pDoc->length; i++)
			pDoc->grid[i] = new bool[12];

		for (int i = 0; i <= pDoc->length; i++)
			for (int j = 0; j <= pDoc->width; j++)
				pDoc->grid[i][j] = false;

		DrawGrid();
		pDoc->canDraw = false;
	}
}


void CMapView::OnBnClicked_10x4()
{
	CMapDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if (pDoc->canDraw){
		pDoc->width = 9;
		pDoc->length = 3;

		pDoc->grid = new bool*[4];
		for (int i = 0; i <= pDoc->length; i++)
			pDoc->grid[i] = new bool[10];
		

		for (int i = 0; i <= pDoc->length; i++)
			for (int j = 0; j <= pDoc->width; j++)
				pDoc->grid[i][j] = false;
		
		DrawGrid();
		pDoc->canDraw = false;
	}
}


void CMapView::OnBnClicked_SubmitMap()
{
	CMapDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->pathSetUpStage = false;
	pDoc->MoveCritter();
/*
	if (validateMap())
	{
		CDialog	m_wndDlg;
		m_wndDlg.Create(IDD_DIALOG1, this);
		m_wndDlg.ShowWindow(SW_SHOW);
	}
	*/
}

 int money = 100;

void CMapView::OnBnClicked_TowerC()
{
	//MessageBox(_T("New towerC (Level 1), your cost is 3 dollars. \n Your range is 10. \n Your power is 1. \n Rate of fire: 1/sec. " ), _T("Tower C"), 
      // MB_ICONINFORMATION | MB_OK);

	
	money -= 3;

	std::string test1 = "Total money you have is 100 dollars. \n New towerC (Level 1), your cost is 3 dollars. \n Your range is 10. \n Your power is 1. \n Rate of fire: 1/sec. \n Your money is now: " + std::to_string(money);
	
	MessageBoxA(NULL, test1.c_str(), "Tower C", MB_OK);

	positioningTower = true;
}
