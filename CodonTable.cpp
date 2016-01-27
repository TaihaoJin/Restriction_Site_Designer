// CodonTable.cpp: implementation of the CCodonTable class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DNA Analysis.h"
#include "CodonTable.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCodonTable::CCodonTable()
{
	strcpy(m_arCodonNodes[0].cCodon,"AAA");
	m_arCodonNodes[0].cAA1='K';
	strcpy(m_arCodonNodes[0].sAA3,"LYS");

	strcpy(m_arCodonNodes[1].cCodon,"AAC");
	m_arCodonNodes[1].cAA1='N';
	strcpy(m_arCodonNodes[1].sAA3,"ASN");

	strcpy(m_arCodonNodes[2].cCodon,"AAG");
	m_arCodonNodes[2].cAA1='K';
	strcpy(m_arCodonNodes[2].sAA3,"LYS");

	strcpy(m_arCodonNodes[3].cCodon,"AAT");
	m_arCodonNodes[3].cAA1='N';
	strcpy(m_arCodonNodes[3].sAA3,"ASN");

	strcpy(m_arCodonNodes[4].cCodon,"ACA");
	m_arCodonNodes[4].cAA1='T';
	strcpy(m_arCodonNodes[4].sAA3,"THR");

	strcpy(m_arCodonNodes[5].cCodon,"ACC");
	m_arCodonNodes[5].cAA1='T';
	strcpy(m_arCodonNodes[5].sAA3,"THR");

	strcpy(m_arCodonNodes[6].cCodon,"ACG");
	m_arCodonNodes[6].cAA1='T';
	strcpy(m_arCodonNodes[6].sAA3,"THR");

	strcpy(m_arCodonNodes[7].cCodon,"ACT");
	m_arCodonNodes[7].cAA1='T';
	strcpy(m_arCodonNodes[7].sAA3,"THR");

	strcpy(m_arCodonNodes[8].cCodon,"AGA");
	m_arCodonNodes[8].cAA1='R';
	strcpy(m_arCodonNodes[8].sAA3,"ARG");

	strcpy(m_arCodonNodes[9].cCodon,"AGC");
	m_arCodonNodes[9].cAA1='S';
	strcpy(m_arCodonNodes[9].sAA3,"SER");

	strcpy(m_arCodonNodes[10].cCodon,"AGG");
	m_arCodonNodes[10].cAA1='R';
	strcpy(m_arCodonNodes[10].sAA3,"ARG");

	strcpy(m_arCodonNodes[11].cCodon,"AGT");
	m_arCodonNodes[11].cAA1='S';
	strcpy(m_arCodonNodes[11].sAA3,"SER");

	strcpy(m_arCodonNodes[12].cCodon,"ATA");
	m_arCodonNodes[12].cAA1='I';
	strcpy(m_arCodonNodes[12].sAA3,"ILE");

	strcpy(m_arCodonNodes[13].cCodon,"ATC");
	m_arCodonNodes[13].cAA1='I';
	strcpy(m_arCodonNodes[13].sAA3,"ILE");

	strcpy(m_arCodonNodes[14].cCodon,"ATG");
	m_arCodonNodes[14].cAA1='M';
	strcpy(m_arCodonNodes[14].sAA3,"MET");

	strcpy(m_arCodonNodes[15].cCodon,"ATT");
	m_arCodonNodes[15].cAA1='I';
	strcpy(m_arCodonNodes[15].sAA3,"ILE");

	strcpy(m_arCodonNodes[16].cCodon,"CAA");
	m_arCodonNodes[16].cAA1='Q';
	strcpy(m_arCodonNodes[16].sAA3,"GLN");

	strcpy(m_arCodonNodes[17].cCodon,"CAC");
	m_arCodonNodes[17].cAA1='H';
	strcpy(m_arCodonNodes[17].sAA3,"HIS");

	strcpy(m_arCodonNodes[18].cCodon,"CAG");
	m_arCodonNodes[18].cAA1='Q';
	strcpy(m_arCodonNodes[18].sAA3,"GLN");

	strcpy(m_arCodonNodes[19].cCodon,"CAT");
	m_arCodonNodes[19].cAA1='H';
	strcpy(m_arCodonNodes[19].sAA3,"HIS");

	strcpy(m_arCodonNodes[20].cCodon,"CCA");
	m_arCodonNodes[20].cAA1='P';
	strcpy(m_arCodonNodes[20].sAA3,"PRO");

	strcpy(m_arCodonNodes[21].cCodon,"CCC");
	m_arCodonNodes[21].cAA1='P';
	strcpy(m_arCodonNodes[21].sAA3,"PRO");

	strcpy(m_arCodonNodes[22].cCodon,"CCG");
	m_arCodonNodes[22].cAA1='P';
	strcpy(m_arCodonNodes[22].sAA3,"PRO");

	strcpy(m_arCodonNodes[23].cCodon,"CCT");
	m_arCodonNodes[23].cAA1='P';
	strcpy(m_arCodonNodes[23].sAA3,"PRO");

	strcpy(m_arCodonNodes[24].cCodon,"CGA");
	m_arCodonNodes[24].cAA1='R';
	strcpy(m_arCodonNodes[24].sAA3,"ARG");

	strcpy(m_arCodonNodes[25].cCodon,"CGC");
	m_arCodonNodes[25].cAA1='R';
	strcpy(m_arCodonNodes[25].sAA3,"ARG");

	strcpy(m_arCodonNodes[26].cCodon,"CGG");
	m_arCodonNodes[26].cAA1='R';
	strcpy(m_arCodonNodes[26].sAA3,"ARG");

	strcpy(m_arCodonNodes[27].cCodon,"CGT");
	m_arCodonNodes[27].cAA1='R';
	strcpy(m_arCodonNodes[27].sAA3,"ARG");

	strcpy(m_arCodonNodes[28].cCodon,"CTA");
	m_arCodonNodes[28].cAA1='L';
	strcpy(m_arCodonNodes[28].sAA3,"LEU");

	strcpy(m_arCodonNodes[29].cCodon,"CTC");
	m_arCodonNodes[29].cAA1='L';
	strcpy(m_arCodonNodes[29].sAA3,"LEU");

	strcpy(m_arCodonNodes[30].cCodon,"CTG");
	m_arCodonNodes[30].cAA1='L';
	strcpy(m_arCodonNodes[30].sAA3,"LEU");

	strcpy(m_arCodonNodes[31].cCodon,"CTT");
	m_arCodonNodes[31].cAA1='L';
	strcpy(m_arCodonNodes[31].sAA3,"LEU");

	strcpy(m_arCodonNodes[32].cCodon,"GAA");
	m_arCodonNodes[32].cAA1='E';
	strcpy(m_arCodonNodes[32].sAA3,"GLU");

	strcpy(m_arCodonNodes[33].cCodon,"GAC");
	m_arCodonNodes[33].cAA1='D';
	strcpy(m_arCodonNodes[33].sAA3,"ASP");

	strcpy(m_arCodonNodes[34].cCodon,"GAG");
	m_arCodonNodes[34].cAA1='E';
	strcpy(m_arCodonNodes[34].sAA3,"GLU");

	strcpy(m_arCodonNodes[35].cCodon,"GAT");
	m_arCodonNodes[35].cAA1='D';
	strcpy(m_arCodonNodes[35].sAA3,"ASP");

	strcpy(m_arCodonNodes[36].cCodon,"GCA");
	m_arCodonNodes[36].cAA1='A';
	strcpy(m_arCodonNodes[36].sAA3,"ALA");

	strcpy(m_arCodonNodes[37].cCodon,"GCC");
	m_arCodonNodes[37].cAA1='A';
	strcpy(m_arCodonNodes[37].sAA3,"ALA");

	strcpy(m_arCodonNodes[38].cCodon,"GCG");
	m_arCodonNodes[38].cAA1='A';
	strcpy(m_arCodonNodes[38].sAA3,"ALA");

	strcpy(m_arCodonNodes[39].cCodon,"GCT");
	m_arCodonNodes[39].cAA1='A';
	strcpy(m_arCodonNodes[39].sAA3,"ALA");

	strcpy(m_arCodonNodes[40].cCodon,"GGA");
	m_arCodonNodes[40].cAA1='G';
	strcpy(m_arCodonNodes[40].sAA3,"GLY");

	strcpy(m_arCodonNodes[41].cCodon,"GGC");
	m_arCodonNodes[41].cAA1='G';
	strcpy(m_arCodonNodes[41].sAA3,"GLY");

	strcpy(m_arCodonNodes[42].cCodon,"GGG");
	m_arCodonNodes[42].cAA1='G';
	strcpy(m_arCodonNodes[42].sAA3,"GLY");

	strcpy(m_arCodonNodes[43].cCodon,"GGT");
	m_arCodonNodes[43].cAA1='G';
	strcpy(m_arCodonNodes[43].sAA3,"GLY");

	strcpy(m_arCodonNodes[44].cCodon,"GTA");
	m_arCodonNodes[44].cAA1='V';
	strcpy(m_arCodonNodes[44].sAA3,"VAL");

	strcpy(m_arCodonNodes[45].cCodon,"GTC");
	m_arCodonNodes[45].cAA1='V';
	strcpy(m_arCodonNodes[45].sAA3,"VAL");

	strcpy(m_arCodonNodes[46].cCodon,"GTG");
	m_arCodonNodes[46].cAA1='V';
	strcpy(m_arCodonNodes[46].sAA3,"VAL");

	strcpy(m_arCodonNodes[47].cCodon,"GTT");
	m_arCodonNodes[47].cAA1='V';
	strcpy(m_arCodonNodes[47].sAA3,"VAL");

	strcpy(m_arCodonNodes[48].cCodon,"TAA");
	m_arCodonNodes[48].cAA1='#';
	strcpy(m_arCodonNodes[48].sAA3,"STP");

	strcpy(m_arCodonNodes[49].cCodon,"TAC");
	m_arCodonNodes[49].cAA1='Y';
	strcpy(m_arCodonNodes[49].sAA3,"TYR");

	strcpy(m_arCodonNodes[50].cCodon,"TAG");
	m_arCodonNodes[50].cAA1='@';
	strcpy(m_arCodonNodes[50].sAA3,"STP");

	strcpy(m_arCodonNodes[51].cCodon,"TAT");
	m_arCodonNodes[51].cAA1='Y';
	strcpy(m_arCodonNodes[51].sAA3,"TYR");

	strcpy(m_arCodonNodes[52].cCodon,"TCA");
	m_arCodonNodes[52].cAA1='S';
	strcpy(m_arCodonNodes[52].sAA3,"SER");

	strcpy(m_arCodonNodes[53].cCodon,"TCC");
	m_arCodonNodes[53].cAA1='S';
	strcpy(m_arCodonNodes[53].sAA3,"SER");

	strcpy(m_arCodonNodes[54].cCodon,"TCG");
	m_arCodonNodes[54].cAA1='S';
	strcpy(m_arCodonNodes[54].sAA3,"SER");

	strcpy(m_arCodonNodes[55].cCodon,"TCT");
	m_arCodonNodes[55].cAA1='S';
	strcpy(m_arCodonNodes[55].sAA3,"SER");

	strcpy(m_arCodonNodes[56].cCodon,"TGA");
	m_arCodonNodes[56].cAA1='&';
	strcpy(m_arCodonNodes[56].sAA3,"STP");

	strcpy(m_arCodonNodes[57].cCodon,"TGC");
	m_arCodonNodes[57].cAA1='C';
	strcpy(m_arCodonNodes[57].sAA3,"CYS");

	strcpy(m_arCodonNodes[58].cCodon,"TGG");
	m_arCodonNodes[58].cAA1='W';
	strcpy(m_arCodonNodes[58].sAA3,"TRP");

	strcpy(m_arCodonNodes[59].cCodon,"TGT");
	m_arCodonNodes[59].cAA1='C';
	strcpy(m_arCodonNodes[59].sAA3,"CYS");

	strcpy(m_arCodonNodes[60].cCodon,"TTA");
	m_arCodonNodes[60].cAA1='L';
	strcpy(m_arCodonNodes[60].sAA3,"LEU");

	strcpy(m_arCodonNodes[61].cCodon,"TTC");
	m_arCodonNodes[61].cAA1='F';
	strcpy(m_arCodonNodes[61].sAA3,"PHE");

	strcpy(m_arCodonNodes[62].cCodon,"TTG");
	m_arCodonNodes[62].cAA1='L';
	strcpy(m_arCodonNodes[62].sAA3,"LEU");

	strcpy(m_arCodonNodes[63].cCodon,"TTT");
	m_arCodonNodes[63].cAA1='F';
	strcpy(m_arCodonNodes[63].sAA3,"PHE");

	strcpy(m_arCodonNodes[64].cCodon,"XXX");
	m_arCodonNodes[64].cAA1='X';
	strcpy(m_arCodonNodes[64].sAA3,"XXX");

	strcpy(m_sAA1,"ACDEFGHIKLMNPQRSTVWY#@&X");
	strcpy(m_sAA3,"ALACYSASPGLUPHEGLYHISILELYSLEUMETASNPROQLNARGSERTHRVALTRPTYRSTPSTPSTPXXX");

	AAToCodon();

	strcpy(m_sNA,"ACGT");

	int nTemp;
	char cTemp;

	for(int i=0;i<65;i++)
	{
		for(int j=0;j<3;j++)
		{
			cTemp=m_arCodonNodes[i].cCodon[j];
			nTemp=IntNA(cTemp);
			m_arCodonNodes[i].nCodon[j]=nTemp;
		}
	}


}

CCodonTable::~CCodonTable()
{

}

//int CCodonTable::IntAA(char sAA0[], int nKey)
int CCodonTable::IntAA(char sAA0[])
{
	int i,j;
	int nAA=23;
	char sAA[4];

	for(i=0;i<23;i++)
	{
		for(j=0;j<3;j++)
		{
			sAA[j]=m_sAA3[3*i+j];
		}
		if(strcmp(sAA,sAA0)==0)
		{
			nAA=i;
			break;
		}
	}
	return nAA;
}

int CCodonTable::IntAA(char cAA)
{
	int i;
	int nAA=23;

	for(i=0;i<24;i++)
	{
		if(cAA==m_sAA1[i])
		{
			nAA=i;
			break;
		}
	}
	return nAA;
}

int CCodonTable::IntNA(char cNA)
{
	int nNA=100;
	for(int i=0;i<4;i++)
	{
		if(cNA==m_sNA[i])
		{
			nNA=i;
			break;
		}
	}
	return nNA;
}

vector <int> CCodonTable::IntNASeq(CString sNASeq)
{
	char cTemp;
	int nTemp;
	int nSize=sNASeq.GetLength();
	vector <int> nvIntSeq;
	for(int i=0;i<nSize;i++)
	{
		cTemp=sNASeq[i];
		nTemp=IntNA(cTemp);
		nvIntSeq.push_back(nTemp);
	}
	return nvIntSeq;
}

vector <int> CCodonTable::IntAASeq(CString sAASeq)
{
	char cTemp;
	int nTemp;
	int nSize=sAASeq.GetLength();
	vector <int> nvIntSeq;
	for(int i=0;i<nSize;i++)
	{
		cTemp=sAASeq[i];
		nTemp=IntAA(cTemp);
		nvIntSeq.push_back(nTemp);
	}
	return nvIntSeq;
}

void CCodonTable::AAToCodon()
{
	int i,nTemp;
	char cTemp;
	for(i=0;i<24;i++)
	{
		vector <int> anVect;
		m_nvvAAToCodon.push_back(anVect);
	}
	for(i=0;i<65;i++)
	{
		cTemp=m_arCodonNodes[i].cAA1;
		nTemp=IntAA(cTemp);
		m_nvvAAToCodon[nTemp].push_back(i);
	}
}

int CCodonTable::CodonIndex(int nCodon0[])
{
	int nCodon=16*nCodon0[0]+4*nCodon0[1]+nCodon0[2];
	if(nCodon<0||nCodon>63)
		nCodon=64;
	return nCodon;
}

int CCodonTable::NADiff(int nCodon1, int nCodon2)
{
	int nDiff,i;
	nDiff=0;
	char cTemp1,cTemp2;
	for(i=0;i<3;i++)
	{
		cTemp1=m_arCodonNodes[nCodon1].cCodon[i];
		cTemp2=m_arCodonNodes[nCodon2].cCodon[i];
		if(cTemp1!=cTemp2)
		{
			nDiff++;
		}
	}
	return nDiff;
}

vector <IntVect> CCodonTable::Mutation(int nCodon0[3],char cAA,bool bCodonUsage)
{
	int nAA1=Translate(nCodon0);
	int nAA2=IntAA(cAA);
	IntVect anVect=m_nvvAAToCodon.at(nAA2);
	int nSize=anVect.size();
	int pnIndex[20];
	int pnDiff[20];
	int i,nTemp;
	int nIndex=CodonIndex(nCodon0);
	for(i=0;i<nSize;i++)
	{
		nTemp=m_nvvAAToCodon.at(nAA2)[i];
		pnIndex[i]=nTemp;
		if(bCodonUsage)
		{
			pnDiff[i]=-int(100*m_structCodonUsage.fvvCodonUsage.at(nAA2)[i]+.5);
		}
		else
		{
			pnDiff[i]=NADiff(nTemp,nIndex);
		}
	}
	BubbleSort(pnDiff,pnIndex,nSize);
	vector <IntVect> apnVect;
	for(i=0;i<nSize;i++)
	{
		nTemp=pnIndex[i];
		if(nTemp!=nIndex)
		{
			apnVect.push_back(GetCodon(pnIndex[i]));
		}
	}
	return apnVect;
}

vector <CString> CCodonTable::Mutation(int nCodon0[3],char cAA, int nKey)
{
	//including the original codon when nKey==0
	int nAA1=Translate(nCodon0);
	int nAA2=IntAA(cAA);
	IntVect anVect=m_nvvAAToCodon.at(nAA2);
	int nSize=anVect.size();
	int *pnIndex=new int[nSize];
	int *pnDiff=new int[nSize];
	int i,nTemp;
	int nIndex=CodonIndex(nCodon0);
	for(i=0;i<nSize;i++)
	{
		nTemp=m_nvvAAToCodon.at(nAA2)[i];
		pnIndex[i]=nTemp;
		pnDiff[i]=NADiff(nTemp,nIndex);
	}
	BubbleSort(pnDiff,pnIndex,nSize);
	vector <CString> asVect;
	for(i=0;i<nSize;i++)
	{
		nTemp=pnDiff[i];
		if(nTemp>0||nKey==0)
		{
			asVect.push_back(GetStrCodon(pnIndex[i]));
		}
	}
	return asVect;
}

vector <CString> CCodonTable::Mutation(int nCodon0[3],int nAA2, int nKey)
{
	//including the original codon when nKey==0
	int nAA1=Translate(nCodon0);
	IntVect anVect=m_nvvAAToCodon.at(nAA2);
	int nSize=anVect.size();
	int *pnIndex=new int[nSize];
	int *pnDiff=new int[nSize];
	int i,nTemp;
	int nIndex=CodonIndex(nCodon0);
	for(i=0;i<nSize;i++)
	{
		nTemp=m_nvvAAToCodon.at(nAA2)[i];
		pnIndex[i]=nTemp;
		pnDiff[i]=NADiff(nTemp,nIndex);
	}
	BubbleSort(pnDiff,pnIndex,nSize);
	vector <CString> asVect;
	for(i=0;i<nSize;i++)
	{
		nTemp=pnDiff[i];
		if(nTemp>0||nKey==0)
		{
			asVect.push_back(GetStrCodon(pnIndex[i]));
		}
	}
	return asVect;
}


void CCodonTable::BubbleSort(int pnA[], int pnB[], int nSize)
{
	int i,j,nMin,nIMin,nTemp1,nTemp2;
	for(i=0;i<nSize;i++)
	{
		nMin=pnA[i];
		nIMin=i;
		for(j=i+1;j<nSize;j++)
		{
			if(pnA[j]<nMin)
			{
				nIMin=j;
				nMin=pnA[j];
			}
		}
		nTemp1=pnA[i];
		nTemp2=pnB[i];
		pnA[i]=nMin;
		pnB[i]=pnB[nIMin];
		pnA[nIMin]=nTemp1;
		pnB[nIMin]=nTemp2;
	}
}

void CCodonTable::GetCodon(int nIndex, int* pnCodon)
{
	for(int i=0;i<3;i++)
	{
		pnCodon[i]=m_arCodonNodes[nIndex].nCodon[i];
	}
}

IntVect CCodonTable::GetCodon(int nIndex)
{
	IntVect anVect;
	int nTemp;
	for(int i=0;i<3;i++)
	{
		nTemp=m_arCodonNodes[nIndex].nCodon[i];
		anVect.push_back(nTemp);
	}
	return anVect;
}

CString CCodonTable::GetStrCodon(int nIndex)
{
	CString sCodon;
	for(int i=0;i<3;i++)
	{
		sCodon+=m_arCodonNodes[nIndex].cCodon[i];
	}
	return sCodon;
}

int CCodonTable::Translate(int nCodon0[])
{
	int nCodonIndex=CodonIndex(nCodon0);
	return IntAA(m_arCodonNodes[nCodonIndex].cAA1);
}

CString CCodonTable::StrNASeq(IntVect nvNASequence)
{
	CString aString;
	aString.Empty();
	int nSize=nvNASequence.size();
	for(int i=0;i<nSize;i++)
	{
		aString+=m_sNA[nvNASequence[i]];
	}
	return aString;
}

IntVect CCodonTable::ReverseStrand(IntVect nvNASeq)
{
	IntVect avVect;
	int nSize=nvNASeq.size();
	for(int i=0;i<nSize;i++)
	{
		avVect.push_back(3-nvNASeq[nSize-i-1]);
	}
	return avVect;
}

structCodonUsageNode CCodonTable::GetCodonUsage(CString sSeq0)
{
	MakeCodonUsage(sSeq0);
	return m_structCodonUsage;
}

void CCodonTable::MakeCodonUsage(CString sNASeq0)
{
	int i,j,nSize,nLength,nIndex,nCodonIndex;
//	float fSum;
	m_structCodonUsage.nvvAAToCodon=m_nvvAAToCodon;
	nSize=m_nvvAAToCodon.size();
	m_structCodonUsage.fvvCodonUsage.clear();
	for(i=0;i<nSize;i++)
	{
		nLength=m_nvvAAToCodon.at(i).size();
		vector <float> aVect;
		for(j=0;j<nLength;j++)
		{
			aVect.push_back(0.f);
		}
		m_structCodonUsage.fvvCodonUsage.push_back(aVect);
	}
	int nNumCodons=sNASeq0.GetLength()/3;
	int pnCodon[3];
	for(i=0;i<nNumCodons;i++)
	{
		if(i-(i/100)*100==0)
		{
			i=i;
		}
		for(j=0;j<3;j++)
		{
			pnCodon[j]=IntNA(sNASeq0[i*3+j]);
		}
		nIndex=Translate(pnCodon);
		nCodonIndex=CodonIndex(pnCodon);
		nLength=m_nvvAAToCodon.at(nIndex).size();
		for(j=0;j<nLength;j++)
		{
			if(nCodonIndex==m_nvvAAToCodon.at(nIndex)[j])
			{
				m_structCodonUsage.fvvCodonUsage.at(nIndex)[j]+=1.;
			}
		}
	}
}

void CCodonTable::OutputCodonUsage()
{
	FILE *fpOut;
	CString sFileName;
	CFileDialog aFileDlg(false, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, NULL, NULL );
	char* pch="Text file of condon usage (*.txt)\0*.txt\0";
	aFileDlg.m_ofn.lpstrFilter=pch;
	aFileDlg.m_ofn.lpstrTitle="Output the condon usage";
//	strcpy(aFileDlg.m_ofn.lpstrFile,sFileName);
	int i,j,nSize,nLength,nIndex;
	float fSum;

	if(aFileDlg.DoModal()==IDOK)
	{
		sFileName=aFileDlg.GetPathName();
		fpOut=fopen(sFileName,"w");
		nSize=m_structCodonUsage.fvvCodonUsage.size();
		for(i=0;i<nSize;i++)
		{
			fSum=0;
			nLength=m_structCodonUsage.fvvCodonUsage.at(i).size();
			for(j=0;j<nLength;j++)
			{
				fSum+=m_structCodonUsage.fvvCodonUsage.at(i)[j];
			}

			nIndex=m_structCodonUsage.nvvAAToCodon.at(i)[0];
			fprintf(fpOut," %c ",m_arCodonNodes[nIndex].cAA1);

			fprintf(fpOut," %3d ",int(fSum+0.5));

			for(j=0;j<nLength;j++)
			{
				nIndex=m_structCodonUsage.nvvAAToCodon.at(i)[j];
				fprintf(fpOut,"    %s %3d  %6.3f ",m_arCodonNodes[nIndex].cCodon,
					int(m_structCodonUsage.fvvCodonUsage.at(i)[j]+0.5),m_structCodonUsage.fvvCodonUsage.at(i)[j]/fSum);
			}
			fprintf(fpOut,"\n");
		}
		fclose(fpOut);
	}			
}
