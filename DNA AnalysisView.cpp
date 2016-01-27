// DNA AnalysisView.cpp : implementation of the CDNAAnalysisView class
//

#include "stdafx.h"
#include "DNA Analysis.h"

#include "DNA AnalysisDoc.h"
#include "DNA AnalysisView.h"
#include "math.h"
#include "nr.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDNAAnalysisView

IMPLEMENT_DYNCREATE(CDNAAnalysisView, CEditView)

BEGIN_MESSAGE_MAP(CDNAAnalysisView, CEditView)
	//{{AFX_MSG_MAP(CDNAAnalysisView)
	ON_COMMAND(ID_ANALYSIS_DNA_RESTRICTIONSITES, OnAnalysisDnaRestrictionsites)
	ON_COMMAND(ID_FILE_IMPORT_DNASEQUENCE, OnFileImportDnasequence)
	ON_COMMAND(ID_FILE_EXPORT_DNASEQUENCE, OnFileExportDnasequence)
	ON_COMMAND(ID_FILE_EXPORT_PROTEINSEQUENCE, OnFileExportProteinsequence)
	ON_COMMAND(ID_ANALYSIS_DNA_TRANSLATE, OnAnalysisDnaTranslate)
	ON_COMMAND(ID_ANALYSIS_DNA_PRIMERS_POINTMUTATION, OnAnalysisDnaPrimersPointmutation)
	ON_COMMAND(ID_ANALYSIS_DNA_CODONUAGE, OnAnalysisDnaCodonuage)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDNAAnalysisView construction/destruction

CDNAAnalysisView::CDNAAnalysisView()
{
	// TODO: add construction code here
	m_nReadingFrame=0;

}

CDNAAnalysisView::~CDNAAnalysisView()
{
}

BOOL CDNAAnalysisView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Enable word-wrapping

	return bPreCreated;
}

/////////////////////////////////////////////////////////////////////////////
// CDNAAnalysisView drawing

void CDNAAnalysisView::OnDraw(CDC* pDC)
{
	CDNAAnalysisDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDNAAnalysisView printing

BOOL CDNAAnalysisView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default CEditView preparation
	return CEditView::OnPreparePrinting(pInfo);
}

void CDNAAnalysisView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView begin printing.
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CDNAAnalysisView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView end printing
	CEditView::OnEndPrinting(pDC, pInfo);
}

/////////////////////////////////////////////////////////////////////////////
// CDNAAnalysisView diagnostics

#ifdef _DEBUG
void CDNAAnalysisView::AssertValid() const
{
	CEditView::AssertValid();
}

void CDNAAnalysisView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CDNAAnalysisDoc* CDNAAnalysisView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDNAAnalysisDoc)));
	return (CDNAAnalysisDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDNAAnalysisView message handlers

void CDNAAnalysisView::OnAnalysisDnaRestrictionsites() 
{
	// TODO: Add your command handler code here
	OnFileImportDnasequence();

	ConstructPossibleCodons();
	vector <structRestrictionSiteNode> aVector=m_cRestrictionEnzymes.GetRestrictionSites(m_vsPossibleCodons);
	OutputRestrictionSites(aVector);	
}

void CDNAAnalysisView::OnFileImportDnasequence() 
{
	// TODO: Add your command handler code here
	FILE *fpIn;
	CString sFileName;
	CFileDialog aFileDlg( true, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, NULL, NULL );
	char* pch="a ASCII form of DNA sequence file (*.txt or *.seq)\0*.txt;*.seq\0";
	aFileDlg.m_ofn.lpstrFilter=pch;
	aFileDlg.m_ofn.lpstrTitle="Input a DNA sequence file";
//	strcpy(aFileDlg.m_ofn.lpstrFile,m_sAbfFileName);
	CString sTemp;

	if(aFileDlg.DoModal()==IDOK)
	{
		sFileName=aFileDlg.GetPathName();
		fpIn=fopen(sFileName,"r");
		fscanf(fpIn,"%s",sTemp);
		CString sSeqName=PassString(sTemp);
		fscanf(fpIn,"%s",sTemp);
		CString sSequence=PassString(sTemp);
		fclose(fpIn);
		m_sNASequence=sSequence;
		m_nvNASequence=m_cCodonTable.IntNASeq(sSequence);
		int	nTemp=m_nvNASequence.size();
	}	
}

void CDNAAnalysisView::OnFileExportDnasequence() 
{
	// TODO: Add your command handler code here
	FILE *fpOut;
	CString sFileName;
	CFileDialog aFileDlg(false, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, NULL, NULL );
	char* pch="a ASCII form of DNA sequence file (*.txt or *.seq)\0*.txt;*.seq\0";
	aFileDlg.m_ofn.lpstrFilter=pch;
	aFileDlg.m_ofn.lpstrTitle="Input a DNA sequence file";
	strcpy(aFileDlg.m_ofn.lpstrFile,m_sNASeqName+"Seq");
	CString sSeqName, sSequence;

	if(aFileDlg.DoModal()==IDOK)
	{
		sFileName=aFileDlg.GetPathName();
		fpOut=fopen(sFileName,"w");
		fprintf(fpOut,">%s",m_sNASeqName);
		fprintf(fpOut,"%s",m_sNASequence);
		fclose(fpOut);
	}		
}

void CDNAAnalysisView::OnFileExportProteinsequence() 
{
	// TODO: Add your command handler code here
	FILE *fpOut;
	CString sFileName;
	CFileDialog aFileDlg(false, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, NULL, NULL );
	char* pch="ASCII form of the protein sequence file (*.txt or *.seq)\0*.txt;*.seq\0";
	aFileDlg.m_ofn.lpstrFilter=pch;
	aFileDlg.m_ofn.lpstrTitle="Input a protein sequence file";
	sFileName=m_sNASeqName+"Seq";
	strcpy(aFileDlg.m_ofn.lpstrFile,sFileName);
	CString sSeqName, sSequence;

	if(aFileDlg.DoModal()==IDOK)
	{
		sFileName=aFileDlg.GetPathName();
		fpOut=fopen(sFileName,"w");
		fprintf(fpOut,">%s",m_sNASeqName);
		fprintf(fpOut,"%s",m_sAASequence);
		fclose(fpOut);
	}			
}

void CDNAAnalysisView::OnAnalysisDnaTranslate() 
{
	// TODO: Add your command handler code here
	int nSize=m_nvNASequence.size();
	int nShift=0;
	int i,nPosition;
	int *pnCodon=new int[3];
	char cAA;
	nPosition=nShift;
	m_sAASequence.Empty();
	while(nPosition<nSize)
	{
		for(i=0;i<3;i++)
		{
			pnCodon[i]=m_nvNASequence[nPosition+i];
		}
		cAA=m_cCodonTable.Translate(pnCodon);
		m_sAASequence+=cAA;
		nPosition+=3;
	}	
}

void CDNAAnalysisView::OnAnalysisDnaPrimersPointmutation() 
{
	// TODO: Add your command handler code here
	OnFileImportDnasequence();
	CPointMutationPrimerDlg aDlg;
	vector <IntVect> anvvCodon;
	IntVect anvCodon;
	int nCodon[3];
	char cAA1,cAA2;
	int nMinLength[3],nPosition;
	int nDiff,nPosition1,nPosition2;
	int i, nLength;
	int nTemp;
	bool bCodonUsage=false;

	CString sPrimer;
	if(aDlg.DoModal()==IDOK)
	{
		aDlg.GetPMPrimerOption(cAA1,cAA2,nPosition,nMinLength,bCodonUsage);
		nTemp=m_nvNASequence.size();
		for(i=0;i<3;i++)
		{
			nCodon[i]=m_nvNASequence[3*(nPosition-1)+i];
		}

		if(bCodonUsage)
		{
			m_cCodonTable.MakeCodonUsage(m_sNASequence);
		}

		anvvCodon=m_cCodonTable.Mutation(nCodon,cAA2,bCodonUsage);
		if(anvvCodon.size()>0)
			anvCodon=anvvCodon[0];
		nDiff=0;
		for(i=0;i<3;i++)
		{
			nTemp=anvCodon[i];
			if(nCodon[i]!=nTemp)
			{
				nDiff++;
			}
		}
		nLength=(nMinLength[nDiff-1]-3)/2;
		int nPosition3=3*(nPosition-1);
		nPosition1=nPosition3-nLength;
		if(nPosition1<0)
			nPosition1=0;
		while(nPosition1>0&&m_nvNASequence[nPosition1]==0||m_nvNASequence[nPosition1]==3)
		{
			nPosition1--;
		}

		nPosition2=nPosition3+nLength+3;
		if(nPosition2>=m_nvNASequence.size())
			nPosition2=m_nvNASequence.size()-1;
		while(nPosition2<m_nvNASequence.size()&&m_nvNASequence[nPosition2]==0||m_nvNASequence[nPosition2]==3)
		{
			nPosition2++;
		}

		IntVect bnvSeq;
		for(i=nPosition1;i<=nPosition2;i++)
		{
			if(i>=nPosition3&&i<=nPosition3+2)
			{
				nTemp=anvCodon[i-nPosition3];
			}
			else
			{
				nTemp=m_nvNASequence[i];
			}
			bnvSeq.push_back(nTemp);
		}

		CString sPrimer=m_cCodonTable.StrNASeq(bnvSeq);
		IntVect cnvSeq=m_cCodonTable.ReverseStrand(bnvSeq);

		FILE *fpOut;
		CString sFileName;
		CFileDialog aFileDlg(false, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, NULL, NULL );
		char* pch="ASCII form of the DNA sequence file (*.txt or *.seq)\0*.txt;*.seq\0";
		aFileDlg.m_ofn.lpstrFilter=pch;
		aFileDlg.m_ofn.lpstrTitle="Output the primer";
		sFileName=m_sNASeqName+"Seq";
		strcpy(aFileDlg.m_ofn.lpstrFile,sFileName);
		CString sSeqName, sSequence;

		if(aFileDlg.DoModal()==IDOK)
		{
			sFileName=aFileDlg.GetPathName();
			fpOut=fopen(sFileName,"a");
			fprintf(fpOut,"s_%c%",cAA1);
			WriteInteger(fpOut,nPosition);
			fprintf(fpOut,"%c %2dmer\n",cAA2,bnvSeq.size());
			fprintf(fpOut,"%s\n",sPrimer);
			fprintf(fpOut,"\n");
			sPrimer=m_cCodonTable.StrNASeq(cnvSeq);
			fprintf(fpOut,"a_%c%",cAA1);
			WriteInteger(fpOut,nPosition);
			fprintf(fpOut,"%c %2dmer\n",cAA2,cnvSeq.size());
			fprintf(fpOut,"%s\n",sPrimer);
			fprintf(fpOut,"\n");
			fclose(fpOut);
		}			

	}	
}

void CDNAAnalysisView::WriteInteger(FILE *fpOut, int nA)
{
	IntVect anVect;
	int nDigits=1;
	anVect.push_back(mod(nA,10));
	nA=nA/10;
	while(nA>0)
	{
		anVect.push_back(mod(nA,10));
		nA/=10;
	}
	nDigits=anVect.size();
	for(int i=0;i<nDigits;i++)
	{
		fprintf(fpOut,"%1d",anVect[nDigits-i-1]);
	}
}

int CDNAAnalysisView::mod(int nA, int nB)
{
	return nA-nB*(nA/nB);
}

void CDNAAnalysisView::OutputRestrictionSites(vector <structRestrictionSiteNode> aVector)
{
	FILE *fpOut;
	CString sFileName;
	CFileDialog aFileDlg(false, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, NULL, NULL );
	char* pch="An text file of restriction sites(*.rst)\0*.rst\0";
	aFileDlg.m_ofn.lpstrFilter=pch;
	aFileDlg.m_ofn.lpstrTitle="Output the restriction sites";
	sFileName=ChangeFileExt(m_sNASeqName,"rst");
//	strcpy(aFileDlg.m_ofn.lpstrFile,sFileName);
	CString sSeqName, sSequence;
	int i,j,nLength,nCutSite;

	int nSize=aVector.size();
	Vec_IO_DP arr(nSize);
	Vec_IO_DP brr(nSize);
	int nTrial;
	for(nTrial=0;nTrial<nSize;nTrial++)
	{
		arr[nTrial]=aVector.at(nTrial).nCuttingPosition;
		brr[nTrial]=double(nTrial);
	}
	NR::sort2(arr,brr);

	if(aFileDlg.DoModal()==IDOK)
	{
		int nNumSites=aVector.size();
		sFileName=aFileDlg.GetPathName();
		fpOut=fopen(sFileName,"w");
		fprintf(fpOut,"  Position    Enzyme     RecSequence                   OregionalSeq   NewSequence      NumMutation  Overhang Cuttings0 Cuttings1\n");
		for(int it=0;it<nNumSites;it++)
		{
			i=int(brr[it]+0.5);
			if(aVector[i].nNumCuttings0==0||aVector[i].nNumMutations==0&&aVector[i].nNumCuttings0==1)
//			if(aVector[i].nNumMutations==0&&aVector[i].nNumCuttings0==1)
			{
				i=int(brr[it]+0.5);
	//			i=it;
				fprintf(fpOut,"%10d    "    ,aVector[i].nCuttingPosition);
				nCutSite=aVector[i].strEnzymeNode.nCutSize;
				fprintf(fpOut,"%s",aVector[i].strEnzymeNode.sName);
				nLength=aVector[i].strEnzymeNode.sName.GetLength();
				for(j=nLength;j<15;j++)
				{
					fprintf(fpOut," ");
				}
				
				nLength=aVector[i].strEnzymeNode.nUnitSize;
				for(j=0;j<nLength;j++)
				{
					if(j==nCutSite)
						fprintf(fpOut,"/");
					fprintf(fpOut,"%c",aVector[i].strEnzymeNode.sRecSeq[j]);
				}
				for(j=nLength;j<29;j++)
				{
					if(j==nCutSite)
						fprintf(fpOut,"/");
					fprintf(fpOut," ");
				}

				nLength=aVector[i].sOriginalSeq.GetLength();
				for(j=0;j<nLength;j++)
				{
					fprintf(fpOut,"%c",aVector[i].sOriginalSeq[j]);
				}
				for(j=nLength;j<14;j++)
				{
					fprintf(fpOut," ");
				}

				nLength=aVector[i].sNewSeq.GetLength();
				for(j=0;j<nLength;j++)
				{
					fprintf(fpOut,"%c",aVector[i].sNewSeq[j]);
				}
				for(j=nLength;j<14;j++)
				{
					fprintf(fpOut," ");
				}
				fprintf(fpOut,"  %9d",aVector[i].nNumMutations);
				fprintf(fpOut,"  %8d",aVector[i].strEnzymeNode.nOverhang);
				fprintf(fpOut,"  %8d",aVector[i].nNumCuttings0);
				fprintf(fpOut,"  %8d",aVector[i].nNumCuttings1);

				fprintf(fpOut,"\n");
	//			fprintf(fpOut,"    %2d\n",aVector[i].strEnzymeNode.nOverhang);
			}
		}
		fclose(fpOut);
	}			
}

CString CDNAAnalysisView::ChangeFileExt(CString sFileName, CString sExt)
{
//	char cTemp;
	CString sNewFileName=sFileName;
	int nLength=sFileName.GetLength();
	for(int i=0;i<3;i++)
	{
		sNewFileName.SetAt(nLength-3+i,sExt[i]);
	}
	return sNewFileName;	
}

void CDNAAnalysisView::ConstructPossibleCodons()
{
	int pnCodon[3];
	int nLength=m_sNASequence.GetLength();
	int nNumCodons=(nLength-m_nReadingFrame)/3;
	int i,j;
	int nKey=0;
	int nAA;

	CString sTr1=PassString(m_sNASequence);
	sTr1.Empty();
	for(i=0;i<m_nReadingFrame;i++)
	{
		sTr1+=m_sNASequence[i];
	}

	if(sTr1.GetLength()>0)
	{
		vector <CString> aVect;
		aVect.push_back(sTr1);
		m_vsPossibleCodons.push_back(aVect);
	}

	for(i=0;i<nNumCodons;i++)
	{
		for(j=0;j<3;j++)
		{
			pnCodon[j]=m_nvNASequence[3*i+j];
		}
		nAA=m_cCodonTable.Translate(pnCodon);
		vector <CString> bVect=m_cCodonTable.Mutation(pnCodon,nAA,nKey);
		m_vsPossibleCodons.push_back(bVect);
	}

	CString sTr2=PassString("AA");
	sTr2.Empty();
	for(i=m_nReadingFrame+3*nNumCodons;i<nLength;i++)
	{
		sTr2+=m_sNASequence[i];
	}
	if(sTr2.GetLength()>0)
	{
		vector <CString> cVect;
		cVect.push_back(sTr2);
		m_vsPossibleCodons.push_back(cVect);
	}
}

CString CDNAAnalysisView::PassString(CString aString)
{
	CString bString;
	bString=aString;
	return bString;
}

void CDNAAnalysisView::OnAnalysisDnaCodonuage() 
{
	// TODO: Add your command handler code here
	OnFileImportDnasequence();
	m_cCodonTable.MakeCodonUsage(m_sNASequence);
	m_cCodonTable.OutputCodonUsage();
}
