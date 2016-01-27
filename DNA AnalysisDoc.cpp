// DNA AnalysisDoc.cpp : implementation of the CDNAAnalysisDoc class
//

#include "stdafx.h"
#include "DNA Analysis.h"

#include "DNA AnalysisDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDNAAnalysisDoc

IMPLEMENT_DYNCREATE(CDNAAnalysisDoc, CDocument)

BEGIN_MESSAGE_MAP(CDNAAnalysisDoc, CDocument)
	//{{AFX_MSG_MAP(CDNAAnalysisDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDNAAnalysisDoc construction/destruction

CDNAAnalysisDoc::CDNAAnalysisDoc()
{
	// TODO: add one-time construction code here

}

CDNAAnalysisDoc::~CDNAAnalysisDoc()
{
}

BOOL CDNAAnalysisDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDNAAnalysisDoc serialization

void CDNAAnalysisDoc::Serialize(CArchive& ar)
{
	// CEditView contains an edit control which handles all serialization
	((CEditView*)m_viewList.GetHead())->SerializeRaw(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CDNAAnalysisDoc diagnostics

#ifdef _DEBUG
void CDNAAnalysisDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDNAAnalysisDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDNAAnalysisDoc commands
