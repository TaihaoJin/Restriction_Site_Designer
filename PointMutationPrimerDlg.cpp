// PointMutationPrimerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DNA Analysis.h"
#include "PointMutationPrimerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPointMutationPrimerDlg dialog


CPointMutationPrimerDlg::CPointMutationPrimerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPointMutationPrimerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPointMutationPrimerDlg)
	m_cOriginalAA = _T("E");
	m_cSubstitution = _T("D");
	m_nPosition = 152;
	m_nMinLength1 = 27;
	m_nMinLength2 = 33;
	m_nMinLength3 = 33;
	m_bMinBaseChange=true;
	m_bCodonUsage=false;
	//}}AFX_DATA_INIT
}


void CPointMutationPrimerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPointMutationPrimerDlg)
	DDX_Text(pDX, IDC_EDIT1, m_cOriginalAA);
	DDX_Text(pDX, IDC_EDIT2, m_cSubstitution);
	DDX_Text(pDX, IDC_EDIT3, m_nPosition);
	DDX_Text(pDX, IDC_EDIT4, m_nMinLength1);
	DDX_Text(pDX, IDC_EDIT5, m_nMinLength2);
	DDX_Text(pDX, IDC_EDIT6, m_nMinLength3);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPointMutationPrimerDlg, CDialog)
	//{{AFX_MSG_MAP(CPointMutationPrimerDlg)
	ON_BN_CLICKED(IDC_MinBaseChange, OnMinBaseChange)
	ON_BN_CLICKED(IDC_CodonUsage, OnCodonUsage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPointMutationPrimerDlg message handlers

CPointMutationPrimerDlg::GetPMPrimerOption(char &cAA1, char &cAA2, int &nPosition, int* pnMinLength, bool &bCodonUsage)
{
	cAA1=m_cOriginalAA[0];
	cAA2=m_cSubstitution[0];
	nPosition=m_nPosition;
	pnMinLength[0]=m_nMinLength1;
	pnMinLength[1]=m_nMinLength2;
	pnMinLength[2]=m_nMinLength3;
	bCodonUsage=m_bCodonUsage;
}

void CPointMutationPrimerDlg::OnMinBaseChange() 
{
	// TODO: Add your control notification handler code here
	m_bMinBaseChange=true;
	m_bCodonUsage=false;
}

void CPointMutationPrimerDlg::OnCodonUsage() 
{
	// TODO: Add your control notification handler code here
	m_bMinBaseChange=false;
	m_bCodonUsage=true;	
}
