
// TowerDefense.h : main header file for the TowerDefense application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CTowerDefenseApp:
// See TowerDefense.cpp for the implementation of this class
//

class CTowerDefenseApp : public CWinApp
{
public:
	CTowerDefenseApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTowerDefenseApp theApp;
