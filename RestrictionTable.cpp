// RestrictionTable.cpp: implementation of the CRestrictionTable class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DNA Analysis.h"
#include "RestrictionTable.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRestrictionTable::CRestrictionTable()
{
	InputCutters();
	for(int i=0;i<123;i++)
	{
		for(int j=0;j<123;j++)
		{
			m_nMatchingBaseTable[i][j]=false;
		}
		m_nMatchingBaseTable[i][i]=true;
	}

	int nA, nB;
//	B = C or G or T
	nA='B';
	nB='C';
	m_nMatchingBaseTable[nA][nB]=true;
	m_nMatchingBaseTable[nB][nA]=true;
	nB='G';
	m_nMatchingBaseTable[nA][nB]=true;
	m_nMatchingBaseTable[nB][nA]=true;
	nB='T';
	m_nMatchingBaseTable[nA][nB]=true;
	m_nMatchingBaseTable[nB][nA]=true;
//H = A or C or T
	nA='H';
	nB='A';
	m_nMatchingBaseTable[nA][nB]=true;
	m_nMatchingBaseTable[nB][nA]=true;
	nB='C';
	m_nMatchingBaseTable[nA][nB]=true;
	m_nMatchingBaseTable[nB][nA]=true;
	nB='T';
	m_nMatchingBaseTable[nA][nB]=true;
	m_nMatchingBaseTable[nB][nA]=true;
//K = G or T
	nA='K';
	nB='G';
	m_nMatchingBaseTable[nA][nB]=true;
	m_nMatchingBaseTable[nB][nA]=true;
	nB='T';
	m_nMatchingBaseTable[nA][nB]=true;
	m_nMatchingBaseTable[nB][nA]=true;
//M = A or C
	nA='M';
	nB='A';
	m_nMatchingBaseTable[nA][nB]=true;
	m_nMatchingBaseTable[nB][nA]=true;
	nB='C';
	m_nMatchingBaseTable[nA][nB]=true;
	m_nMatchingBaseTable[nB][nA]=true;
//N = A or C or G or T
	nA='N';
	nB='A';
	m_nMatchingBaseTable[nA][nB]=true;
	m_nMatchingBaseTable[nB][nA]=true;
	nB='C';
	m_nMatchingBaseTable[nA][nB]=true;
	m_nMatchingBaseTable[nB][nA]=true;
	nB='G';
	m_nMatchingBaseTable[nA][nB]=true;
	m_nMatchingBaseTable[nB][nA]=true;
	nB='T';
	m_nMatchingBaseTable[nA][nB]=true;
	m_nMatchingBaseTable[nB][nA]=true;
//R = A or G
	nA='R';
	nB='A';
	m_nMatchingBaseTable[nA][nB]=true;
	m_nMatchingBaseTable[nB][nA]=true;
	nB='G';
	m_nMatchingBaseTable[nA][nB]=true;
	m_nMatchingBaseTable[nB][nA]=true;
//S = C or G
	nA='S';
	nB='C';
	m_nMatchingBaseTable[nA][nB]=true;
	m_nMatchingBaseTable[nB][nA]=true;
	nB='G';
	m_nMatchingBaseTable[nA][nB]=true;
	m_nMatchingBaseTable[nB][nA]=true;
//V = A or C or G
	nA='V';
	nB='A';
	m_nMatchingBaseTable[nA][nB]=true;
	m_nMatchingBaseTable[nB][nA]=true;
	nB='C';
	m_nMatchingBaseTable[nA][nB]=true;
	m_nMatchingBaseTable[nB][nA]=true;
	nB='G';
	m_nMatchingBaseTable[nA][nB]=true;
	m_nMatchingBaseTable[nB][nA]=true;
//W = A or T
	nA='W';
	nB='A';
	m_nMatchingBaseTable[nA][nB]=true;
	m_nMatchingBaseTable[nB][nA]=true;
	nB='T';
	m_nMatchingBaseTable[nA][nB]=true;
	m_nMatchingBaseTable[nB][nA]=true;
//Y = C or T
	nA='Y';
	nB='C';
	m_nMatchingBaseTable[nA][nB]=true;
	m_nMatchingBaseTable[nB][nA]=true;
	nB='T';
	m_nMatchingBaseTable[nA][nB]=true;
	m_nMatchingBaseTable[nB][nA]=true;
}

CRestrictionTable::~CRestrictionTable()
{

}


void CRestrictionTable::InputCutters()
{
	// TODO: Add your command handler code here
	CString sFileName="C:\\Program Files\\Microsoft Visual Studio\\MyProjects\\DNA Analysis\\cutters1.txt";
	CFileDialog aFileDlg( true, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, NULL, NULL );
	char* pch="A space delimited txt file of restriction sites (*.txt)\0*.txt\0";
	aFileDlg.m_ofn.lpstrFilter=pch;
	aFileDlg.m_ofn.lpstrTitle="Input Cutters.txt";
	strcpy(aFileDlg.m_ofn.lpstrFile,sFileName);

	if(aFileDlg.DoModal()==IDOK)
	{
		sFileName=aFileDlg.GetPathName();
		m_sCutterFileName=sFileName;
		ReadRestrictionSites();
	}
}

void CRestrictionTable::ReadRestrictionSites()
{
	FILE* fp=fopen(m_sCutterFileName,"r");
	int i, nNumEnzymes=0;
	int nTemp1,nTemp2,nTemp3,nTemp4,nTemp5,nTemp6,nTemp7;
	CString sTemp;
	while(!feof(fp))
	{
		structRestrictionEnzymeNode aNode;
		fscanf(fp,"%s",sTemp);
		aNode.sName=PassString(sTemp);
		fscanf(fp,"%d",&nTemp1);
		aNode.nUnitSize=nTemp1;
		fscanf(fp,"%d",&nTemp2);
		aNode.nMatchSize=nTemp2;
		fscanf(fp,"%s",sTemp);
		aNode.sRecSeq=PassString(sTemp);
		fscanf(fp,"%d",&nTemp3);
		aNode.nCutSize=nTemp3;
		fscanf(fp,"%d",&nTemp4);
		aNode.nOverhang=nTemp4;
		fscanf(fp,"%d",&nTemp5);
		aNode.nPalindromic=nTemp5;
		fscanf(fp,"%d",&nTemp6);
		aNode.nSemicolon=nTemp6;
		fscanf(fp,"%d",&nTemp7);
		aNode.nNumSciz=nTemp7;
		for(i=0;i<aNode.nNumSciz;i++)
		{
			CString aString;
			fscanf(fp,"%s",aString);
			aNode.vsScizs.push_back(aString);
		}
		fscanf(fp,"%d",&aNode.nNumCompanies);
		for(i=0;i<aNode.nNumCompanies;i++)
		{
			CString aString;
			fscanf(fp,"%s",aString);
			aNode.vsCompanies.push_back(aString);
		}
		fscanf(fp,"%d",&aNode.nNumRefs);
		for(i=0;i<aNode.nNumRefs;i++)
		{
			int nTemp;
			fscanf(fp,"%s",&nTemp);
			aNode.vnRefs.push_back(nTemp);
		}
		aNode.nTailNs=TailNs(aNode);
		m_vstructEnzymeNodes.push_back(aNode);
		nNumEnzymes++;
	}
}

CString CRestrictionTable::PassString(CString aString)
{
	CString bString=aString;
	return bString;
}

vector <structRestrictionSiteNode> CRestrictionTable::GetRestrictionSites(CString sSeq)
{
	vector <structRestrictionSiteNode> aVector;
	int nSize=sSeq.GetLength();
	int nNumEnzymes=m_vstructEnzymeNodes.size();
	int i,j,nLength,nPosition;
	CString sTemp;
	char cTemp;
	bool bMatch;
	for(nPosition=0;nPosition<nSize;nPosition++)
	{
		for(i=0;i<nNumEnzymes;i++)
		{
			nLength=m_vstructEnzymeNodes[i].sRecSeq.GetLength();
			if(nLength>nSize-nPosition)
			{
				bMatch=false;
			}
			else
			{
				sTemp=m_vstructEnzymeNodes[i].sRecSeq;
				bMatch=true;
				for(j=0;j<nLength;j++)
				{
					cTemp=sTemp[j];
					if(cTemp!='N'&&cTemp!=sSeq[nPosition+j])
					{
						bMatch=false;
						break;
					}
				}
			}
			if(bMatch)
			{
				structRestrictionSiteNode aNode;
				aNode.strEnzymeNode=m_vstructEnzymeNodes[i];
				aNode.nCuttingPosition=nPosition+m_vstructEnzymeNodes[i].nCutSize;
				aVector.push_back(aNode);
			}
		}
	}
	return aVector;
}

int CRestrictionTable::TailNs(structRestrictionEnzymeNode aNode)
{
	int nTailNs=0;
	CString sTemp=aNode.sRecSeq;
	int nIndex=aNode.sRecSeq.GetLength()-1;
	while(nIndex>=0&&sTemp[nIndex]=='N')
	{
		nIndex--;
		nTailNs++;
	}
	return nTailNs;
}

vector <structRestrictionSiteNode> CRestrictionTable::GetRestrictionSites(vector <sVect> vsPossibleCodons)
{
	m_vsPossibleCodons=vsPossibleCodons;
	int nNumCodons=vsPossibleCodons.size();
	int nNumEnzymes=m_vstructEnzymeNodes.size();
	int i,j,nPosition,nRecLength;
	int nLength1=m_vsPossibleCodons.at(0)[0].GetLength();
	int nLength2=m_vsPossibleCodons.at(nNumCodons-1)[0].GetLength();
	int nLength=nLength1+nLength2+3*(nNumCodons-2);
	int nCodon1,nCodon2,nCodonIndex,nIndex;
	bool bMatch;
	CString sRecSeq;
	vector <int> nvCodonIndexes;
	vector <structRestrictionSiteNode> svRestrictionSites;
	int nNumCuttings0,nNumCuttings1,nTotalCuttings=0;
	for(i=0;i<nNumEnzymes;i++)
	{
		sRecSeq=m_vstructEnzymeNodes[i].sRecSeq;
		nRecLength=m_vstructEnzymeNodes[i].nUnitSize-m_vstructEnzymeNodes[i].nTailNs;
		nNumCuttings0=0;
		nNumCuttings1=0;
		for(nPosition=0;nPosition<nLength-nRecLength;nPosition++)
		{
			bMatch=true;
			if(nPosition<nLength1)
			{
				nCodon1=0;
				nCodon2=(nPosition+nRecLength-nLength1)/3+1;
			}
			else
			{
				nCodon1=(nPosition-nLength1)/3+1;
				nCodon2=(nPosition+nRecLength-nLength1)/3+1;
			}
//			if(nPosition-(nPosition/100)*100==0)
			if(nPosition==117)
			{
				nPosition=nPosition;
			}
			nvCodonIndexes.clear();
			for(j=nCodon1;j<=nCodon2;j++)
			{
				if(!PossibleCuttingSite(nPosition,j,nLength1,sRecSeq,nRecLength,nCodonIndex))
				{
					bMatch=false;
					break;
				}
				else
				{
					nvCodonIndexes.push_back(nCodonIndex);
				}
			}
			if(bMatch)
			{
				structRestrictionSiteNode aNode;
				aNode.nCuttingPosition=nPosition+m_vstructEnzymeNodes[i].nCutSize;
				aNode.nNumMutations=0;
				for(j=nCodon1;j<=nCodon2;j++)
				{
					nIndex=nvCodonIndexes[j-nCodon1];
					aNode.sOriginalSeq+=m_vsPossibleCodons.at(j)[0];
					aNode.sNewSeq+=m_vsPossibleCodons.at(j)[nIndex];
					if(nIndex!=0) aNode.nNumMutations++;
				}
				aNode.strEnzymeNode=m_vstructEnzymeNodes[i];
				svRestrictionSites.push_back(aNode);
				if(aNode.nNumMutations==0)
					nNumCuttings0++;
				nNumCuttings1++;
				nTotalCuttings++;
			}
		}
		for(j=nTotalCuttings-1;j>=nTotalCuttings-nNumCuttings1;j--)
		{
			svRestrictionSites[j].nNumCuttings0=nNumCuttings0;
			svRestrictionSites[j].nNumCuttings1=nNumCuttings1;
		}
			
	}
	return svRestrictionSites;
}

bool CRestrictionTable::PossibleCuttingSite(int nPosition,int j0,int nLength1,CString sRecSeq,int nRecLength,int &nCodonIndex)
{
	bool bCutting=true;
	char cA,cB;
	int nShift=(3*(j0-1)+nLength1)-nPosition;
	if(j0==0)
		nShift=-nPosition;
	int nSize=m_vsPossibleCodons.at(j0).size();
	int i,k,nTemp;
	for(i=0;i<nSize;i++)
	{
		bCutting=true;
		CString sCodon=m_vsPossibleCodons.at(j0)[i];
		for(k=0;k<3;k++)
		{
			nTemp=k+nShift;
			if(nTemp>=0&&nTemp<nRecLength)
			{
//				if(sCodon[k]!=sRecSeq[nTemp])
				cA=sCodon[k];
				cB=sRecSeq[nTemp];
				if(!MatchingBase(cA,cB))
				{
					bCutting=false;
					break;
				}
			}
		}
		if(bCutting)
		{
			nCodonIndex=i;
			break;
		}
	}
	return bCutting;
}

bool CRestrictionTable::IdenticalRestrictionEnzyme(int nIndex1, int nIndex2)
{
	if(m_vstructEnzymeNodes[nIndex1].sRecSeq==m_vstructEnzymeNodes[nIndex2].sRecSeq)
		return true;
	else
		return false;
}

bool CRestrictionTable::ComplementaryEnzyme(int nIndex1, int nIndex2)
{
	bool bComp=false;
	int i;
	if(m_vstructEnzymeNodes[nIndex1].nOverhang==m_vstructEnzymeNodes[nIndex2].nOverhang&&m_vstructEnzymeNodes[nIndex1].nOverhang!=0)
	{
		int nUnitSize=m_vstructEnzymeNodes[nIndex1].nUnitSize;
		int nCutSize=m_vstructEnzymeNodes[nIndex1].nCutSize;
		int n1=nCutSize;
		int n2=nUnitSize-nCutSize;
		if(n1>n2)
		{
			n1=n2;
			n2=nCutSize;
		}

		CString sT1=PassString("first");

		sT1.Empty();
		for(i=n1;i<n2;i++)
		{
			sT1=+m_vstructEnzymeNodes[nIndex1].sRecSeq[i];
		}

		nUnitSize=m_vstructEnzymeNodes[nIndex1].nUnitSize;
		nCutSize=m_vstructEnzymeNodes[nIndex1].nCutSize;
		n1=nCutSize;
		n2=nUnitSize-nCutSize;
		if(n1>n2)
		{
			n1=n2;
			n2=nCutSize;
		}

		CString sT2=PassString("second");
		sT2.Empty();
		for(i=n1;i<n2;i++)
		{
			sT2=+m_vstructEnzymeNodes[nIndex2].sRecSeq[i];
		}

		if(sT1==sT2)
			bComp=true;
	}
	return bComp;
}

bool CRestrictionTable::MatchingBase(char cA, char cB)
{
	return m_nMatchingBaseTable[cA][cB];
}
