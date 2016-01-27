// DNA Analysis.h : main header file for the DNA ANALYSIS application
//

#if !defined(AFX_DNAANALYSIS_H__A408540A_FBE9_42F8_96D3_D86CD209EAA1__INCLUDED_)
#define AFX_DNAANALYSIS_H__A408540A_FBE9_42F8_96D3_D86CD209EAA1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDNAAnalysisApp:
// See DNA Analysis.cpp for the implementation of this class
//

class CDNAAnalysisApp : public CWinApp
{
public:
	CDNAAnalysisApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDNAAnalysisApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDNAAnalysisApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DNAANALYSIS_H__A408540A_FBE9_42F8_96D3_D86CD209EAA1__INCLUDED_)
