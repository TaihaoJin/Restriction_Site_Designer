// DNA AnalysisView.h : interface of the CDNAAnalysisView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DNAANALYSISVIEW_H__3C60B0DF_0949_4B49_B7B9_794BC6EDAEDC__INCLUDED_)
#define AFX_DNAANALYSISVIEW_H__3C60B0DF_0949_4B49_B7B9_794BC6EDAEDC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <vector>
#include "structures_DNA.h"
#include "CodonTable.h"
#include "PointMutationPrimerDlg.h"
#include "RestrictionTable.h"

using namespace std;


class CDNAAnalysisView : public CEditView
{
protected: // create from serialization only
	CDNAAnalysisView();
	DECLARE_DYNCREATE(CDNAAnalysisView);
	CString PassString(CString aString);

// Attributes
protected:
	CString m_sNASequence;
	CString m_sNASeqName;
	CString m_sAASequence;
	CString m_sAASeqName;
	vector <int> m_nvNASequence;
	vector <int> m_nvAASequence;
	CCodonTable m_cCodonTable;
	CRestrictionTable m_cRestrictionEnzymes;
	CString ChangeFileExt(CString sFileName, CString sExt);
	void OutputRestrictionSites(vector <structRestrictionSiteNode> aVector);
	int m_nReadingFrame; //0: na 0-2; 1: na 1-3; 2: na 2-4;
	vector <sVect> m_vsPossibleCodons;
public:
	CDNAAnalysisDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDNAAnalysisView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void ConstructPossibleCodons();
	int mod(int nA, int nB);
	void WriteInteger(FILE* fpOut, int nA);
	virtual ~CDNAAnalysisView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDNAAnalysisView)
	afx_msg void OnAnalysisDnaRestrictionsites();
	afx_msg void OnFileImportDnasequence();
	afx_msg void OnFileExportDnasequence();
	afx_msg void OnFileExportProteinsequence();
	afx_msg void OnAnalysisDnaTranslate();
	afx_msg void OnAnalysisDnaPrimersPointmutation();
	afx_msg void OnAnalysisDnaCodonuage();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DNA AnalysisView.cpp
inline CDNAAnalysisDoc* CDNAAnalysisView::GetDocument()
   { return (CDNAAnalysisDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DNAANALYSISVIEW_H__3C60B0DF_0949_4B49_B7B9_794BC6EDAEDC__INCLUDED_)
