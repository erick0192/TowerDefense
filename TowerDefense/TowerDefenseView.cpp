
// TowerDefenseView.cpp : implementation of the CTowerDefenseView class
//

#include "stdafx.h"

//	<added pragmas>
#include "TowerA.h"
//	</added pragmas>

// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TowerDefense.h"
#endif

#include "TowerDefenseDoc.h"
#include "TowerDefenseView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//  <added pragmas>

#include <string>
//  </added pragmas>

// CTowerDefenseView

IMPLEMENT_DYNCREATE(CTowerDefenseView, CView)

BEGIN_MESSAGE_MAP(CTowerDefenseView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON1, &CTowerDefenseView::OnBnClicked_12x6)
	ON_BN_CLICKED(IDC_BUTTON2, &CTowerDefenseView::OnBnClicked_10x4)
	ON_BN_CLICKED(IDC_BUTTON3, &CTowerDefenseView::OnBnClicked_Submit)
	ON_BN_CLICKED(IDC_BUTTON4, &CTowerDefenseView::OnBnClicked_BeginGame)
	ON_BN_CLICKED(IDC_BUTTON5, &CTowerDefenseView::OnBnClicked_BuyTowerA)
	ON_BN_CLICKED(IDC_BUTTON6, &CTowerDefenseView::OnBnClicked_UpgradeA)
	ON_BN_CLICKED(IDC_BUTTON7, &CTowerDefenseView::OnBnClicked_TowerB)
	ON_BN_CLICKED(IDC_BUTTON8, &CTowerDefenseView::OnBnClicked_UpgradeB)
	ON_BN_CLICKED(IDC_BUTTON9, &CTowerDefenseView::OnBnClicked_TowerC)
	ON_BN_CLICKED(IDC_BUTTON10, &CTowerDefenseView::OnBnClicked_UpgradeC)
END_MESSAGE_MAP()

// CTowerDefenseView construction/destruction

CTowerDefenseView::CTowerDefenseView()
{
	// TODO: add construction code here

}

CTowerDefenseView::~CTowerDefenseView()
{
}

BOOL CTowerDefenseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTowerDefenseView drawing

void CTowerDefenseView::OnDraw(CDC* /*pDC*/)
{
	CTowerDefenseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;


	// TODO: add draw code for native data here
}




/////////////////////////////Erick's Functions//////////////////////////////////////////////////////////////
CBrush tBrush(RGB(0, 0, 255));
CBrush sBrush(RGB(0, 255, 0));
CBrush pBrush(RGB(255, 0, 0));

//function to draw the grid
void CTowerDefenseView::DrawGrid()
{
		CTowerDefenseDoc* pDoc = GetDocument();
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

void CTowerDefenseView::ClearGrid()
{
	CTowerDefenseDoc* pDoc = GetDocument();
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
void CTowerDefenseView::OnLButtonDown(UINT /* nFlags*/, CPoint point)
{

	CTowerDefenseDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (!pDoc)
			return;
	if((positioningTower)&&(!pDoc->pathSetUpStage)&&(!pDoc->Gaming))			//to move to TowerView later
	{       

		int x = point.x - (point.x % 100), y = point.y - (point.y % 100);
		if(pDoc->grid[y/100][x/100]){
			MessageBox(_T("Cannot place tower in a path cell"), _T("Error"), 
		  MB_ICONERROR | MB_OK);
		}
		else{
			CBrush towerBrush(RGB(255, 255, 255));
			CDC *pDC = GetDC();
			pDC->SelectObject(towerBrush);
			CPoint p1(x+20, y+20), p2(x + 80, y + 80);
			CRect r(p1, p2);
			pDC->Rectangle(r);
			positioningTower = false;

			Tower* a;
			switch(towerType)
			{
				case 'A':
					a = new TowerA(x+50, y+50, pDoc->level);
					break;
				default:
					a = new TowerA(x+50, y+50, pDoc->level);
			}	
			pDoc->towers.push_back(a);
		}
	}
	else 
	{
	CTowerDefenseDoc* pDoc = GetDocument();
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
void CTowerDefenseView::clearSuggestion(CPoint p1)
{
	CTowerDefenseDoc* pDoc = GetDocument();
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
void CTowerDefenseView::clearInitSuggestions()
{
	CTowerDefenseDoc* pDoc = GetDocument();
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
void CTowerDefenseView::setSuggestions(CPoint* sU, CPoint* sD, CPoint* sL, CPoint* sR, CPoint p1)
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
void CTowerDefenseView::drawSuggestion(CPoint p1)
{
	CTowerDefenseDoc* pDoc = GetDocument();
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

void CTowerDefenseView::DisplayCritter(int x, int y)
{
	/*
	CTowerDefenseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	*/
	CDC *pDC = GetDC();

	pDC->SelectObject(sBrush);
	CPoint p1(x, y), p2(x+20, y+20);
	CRect r(p1, p2);
	pDC->Rectangle(r);

}


void CTowerDefenseView::RedrawGame()
{
	CTowerDefenseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;



	CDC *pDC = GetDC();

/*	for (int i = 0; i <= (pDoc->width * 100); i += 100)
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
	vector<Tower*> towers = pDoc->towers;
	CBrush towerBrush(RGB(255, 255, 255));
	pDC->SelectObject(towerBrush);
	for( int i = 0; i < (int)towers.size(); i++)
	{
		CPoint p1(towers[i]->getX()-30, towers[i]->getY()-30), p2(towers[i]->getX()+30, towers[i]->getY()+30);
		CRect r(p1, p2);
		pDC->Rectangle(r);
	}

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////










// CTowerDefenseView printing

BOOL CTowerDefenseView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTowerDefenseView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTowerDefenseView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CTowerDefenseView diagnostics

#ifdef _DEBUG
void CTowerDefenseView::AssertValid() const
{
	CView::AssertValid();
}

void CTowerDefenseView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTowerDefenseDoc* CTowerDefenseView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTowerDefenseDoc)));
	return (CTowerDefenseDoc*)m_pDocument;
}
#endif //_DEBUG


// CTowerDefenseView message handlers


void CTowerDefenseView::OnBnClicked_12x6()
{
	CTowerDefenseDoc* pDoc = GetDocument();
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


void CTowerDefenseView::OnBnClicked_10x4()
{
	CTowerDefenseDoc* pDoc = GetDocument();
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


void CTowerDefenseView::OnBnClicked_Submit()
{
	CTowerDefenseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->pathSetUpStage = false;
}


void CTowerDefenseView::OnBnClicked_BeginGame()
{
	CTowerDefenseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->Gaming = true;
	pDoc->GameOn();
}


int money = 100;

void CTowerDefenseView::OnBnClicked_BuyTowerA()
{
	money -= 3;

	std::string test1 = "New towerA (Level 1), your cost is 3 dollars. \n Your range is 5. \n Your power is 1. \n Rate of fire: 1/sec. \n Your money is now: " + std::to_string(money);
	
	MessageBoxA(NULL, test1.c_str(), "Tower A", MB_OK);

	positioningTower = true;

	towerType = 'A';
	//p->setMoneyAmount(money);
}


void CTowerDefenseView::OnBnClicked_UpgradeA()
{
	int level = 0;
	level+=1;
	int cost = 3;
	int range = 5;
	int power = 1;
	int rateOfFire = 1;

	if(level==1){
	money -= 3;
	}
	else
	money -=3*level;

	std::string test1 = "New towerA (Level " + std::to_string(level+1) + " ), your cost is " + std::to_string(cost*2)  + " dollars. \n Your range is " + std::to_string(range+5) + " .\n Your power is " + std::to_string(power++) + ". \n Rate of fire: " + std::to_string(rateOfFire*2) + "/sec. \n Your money is now: " + std::to_string(money);
	
	MessageBoxA(NULL, test1.c_str(), "Tower A", MB_OK);

	positioningTower = true;
	

	//p->setMoneyAmount(money);
}



void CTowerDefenseView::OnBnClicked_TowerB()
{
	money -= 3;

	std::string test1 = "New towerB (Level 1), your cost is 3 dollars. \n Your range is 10. \n Your power is 2. \n Rate of fire: 2/sec. \n Your money is now: " + std::to_string(money);
	
	MessageBoxA(NULL, test1.c_str(), "Tower B", MB_OK);

	positioningTower = true;

	towerType = 'B';
}


void CTowerDefenseView::OnBnClicked_UpgradeB()
{
	int level = 0;
	level+=1;
	int cost = 3;
	int range = 10;
	int power = 2;
	int rateOfFire = 2;

	if(level==1){
	money -= 3;
	}
	else
	money -=3*level;

	std::string test1 = "New towerB (Level " + std::to_string(level+1) + " ), your cost is " + std::to_string(cost*2)  + " dollars. \n Your range is " + std::to_string(range+5) + " .\n Your power is " + std::to_string(power++) + ". \n Rate of fire: " + std::to_string(rateOfFire*2) + "/sec. \n Your money is now: " + std::to_string(money);
	
	MessageBoxA(NULL, test1.c_str(), "Tower B", MB_OK);

	positioningTower = true;
}


void CTowerDefenseView::OnBnClicked_TowerC()
{
	money -= 3;

	std::string test1 = "New towerC (Level 1), your cost is 3 dollars. \n Your range is 15. \n Your power is 3. \n Rate of fire: 3/sec. \n Your money is now: " + std::to_string(money);
	
	MessageBoxA(NULL, test1.c_str(), "Tower C", MB_OK);

	positioningTower = true;

	towerType = 'C';
}


void CTowerDefenseView::OnBnClicked_UpgradeC()
{
	int level = 0;
	level+=1;
	int cost = 3;
	int range = 15;
	int power = 3;

	int rateOfFire = 3;

	if(level==1){
	money -= 3;
	}
	else
	money -=3*level;

	std::string test1 = "New towerC (Level " + std::to_string(level+1) + " ), your cost is " + std::to_string(cost*2)  + " dollars. \n Your range is " + std::to_string(range+5) + " .\n Your power is " + std::to_string(power++) + ". \n Rate of fire: " + std::to_string(rateOfFire*2) + "/sec. \n Your money is now: " + std::to_string(money);
	
	MessageBoxA(NULL, test1.c_str(), "Tower C", MB_OK);
   
	positioningTower = true;
}
