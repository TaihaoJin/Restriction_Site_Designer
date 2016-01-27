// DNA AnalysisDoc.h : interface of the CDNAAnalysisDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DNAANALYSISDOC_H__C0648CD1_E491_4535_8635_42D879078F16__INCLUDED_)
#define AFX_DNAANALYSISDOC_H__C0648CD1_E491_4535_8635_42D879078F16__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDNAAnalysisDoc : public CDocument
{
protected: // create from serialization only
	CDNAAnalysisDoc();
	DECLARE_DYNCREATE(CDNAAnalysisDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDNAAnalysisDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDNAAnalysisDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDNAAnalysisDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DNAANALYSISDOC_H__C0648CD1_E491_4535_8635_42D879078F16__INCLUDED_)
