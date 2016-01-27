#if !defined(AFX_POINTMUTATIONPRIMERDLG_H__A379504C_57E4_4B3D_B508_D6D8DA77F780__INCLUDED_)
#define AFX_POINTMUTATIONPRIMERDLG_H__A379504C_57E4_4B3D_B508_D6D8DA77F780__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PointMutationPrimerDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPointMutationPrimerDlg dialog

class CPointMutationPrimerDlg : public CDialog
{
// Construction
public:
	GetPMPrimerOption(char &cAA1, char &cAA2, int &nPosition,  int* pnMinLength, bool &bCodonUsage);
	CPointMutationPrimerDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPointMutationPrimerDlg)
	enum { IDD = IDD_PointMutationPrimers };
	CString	m_cOriginalAA;
	CString	m_cSubstitution;
	int		m_nPosition;
	int		m_nMinLength1;
	int		m_nMinLength2;
	int		m_nMinLength3;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPointMutationPrimerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	bool m_bCodonUsage;
	bool m_bMinBaseChange;

	// Generated message map functions
	//{{AFX_MSG(CPointMutationPrimerDlg)
	afx_msg void OnMinBaseChange();
	afx_msg void OnCodonUsage();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POINTMUTATIONPRIMERDLG_H__A379504C_57E4_4B3D_B508_D6D8DA77F780__INCLUDED_)
