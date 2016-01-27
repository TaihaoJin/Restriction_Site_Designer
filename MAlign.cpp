// MAlign.cpp: implementation of the CMAlign class.
//
//////////////////////////////////////////////////////////////////////



#include "stdafx.h"
#include "MAlign.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif



//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////



CMAlign::CMAlign()
{
	m_nNumOfSeq=0;
	strcpy(m_sAminoAcidNames,".ACDEFGHIKLMNPQRSTVWY");
}



CMAlign::~CMAlign()
{
}



void CMAlign::ReadMAlign()
{
	FILE* GCGFile;
	char* pch="Multiple Sequence Alignment GCG format (*.gcg or *.msf)\0*.gcg\0*.msf\0\0";
	CFileDialog aFileDlg( true, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT|OFN_EXPLORER|OFN_ENABLESIZING, NULL, NULL );
	aFileDlg.m_ofn.lpstrFilter=pch;
	char aString[80];
	vector <bool> bAssigned;
	bool bReadChannelName=false;
	if(aFileDlg.DoModal()==IDOK)
	{
		m_sMAlignFileName=aFileDlg.GetPathName();
		GCGFile=fopen(m_sMAlignFileName,"r");
		m_nNumOfSeq=0;
		while(!feof(GCGFile))
		{
			fscanf(GCGFile,"%s",aString);
			if(strcmp(aString,"Name:")==0)
			{
				fscanf(GCGFile,"%s",aString);
				m_nNumOfSeq++;
				bAssigned.push_back(false);
				m_vectsSeqNames.push_back(aString);
			}
			if(strcmp(aString,"//")==0)
			{
				while(!feof(GCGFile))
				{
					for(int i=0;i<m_nNumOfSeq;i++)					
					{
						if(!bReadChannelName)fscanf(GCGFile,"%s",aString);
						bReadChannelName=false;
						for(int j=0;j<5;j++)
						{
							if(!feof(GCGFile))
							{
								fscanf(GCGFile,"%s",aString);
								if(IsChannelName(aString))
								{
									j=5;
									bReadChannelName=true;
								}
								else
								{
									if(!(bAssigned[i]))
									{
										m_vectsSequence.push_back(aString);
										bAssigned[i]=true;
									}
									else
									{
										m_vectsSequence[i].append(aString);
									}
								}
							}
						}
					}
				}			
			}
		}
	}
	PositionConversion();
	OutputMAlign();
}


void CMAlign::OutputMAlign()
{
	FILE* GCGFile;
	char* pch="Multiple Sequence Alignment GCG format (*.gcg or *.msf)\0*.gcg\0*.msf\0\0";
	CFileDialog aFileDlg( false, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT|OFN_EXPLORER|OFN_ENABLESIZING, NULL, NULL );
	aFileDlg.m_ofn.lpstrFilter=pch;
	int i,j;
	char sLine[5000];
//	if(aFileDlg.DoModal()==IDOK)
//	{
		m_sMAlignFileName="Test.GCG";
//		m_sMAlignFileName=aFileDlg.GetPathName();
		GCGFile=fopen(m_sMAlignFileName,"w");
		for(i=0;i<m_nNumOfSeq;i++)
		{
			strcpy(sLine,m_vectsSeqNames[i].c_str());
			fprintf(GCGFile,"%s\n",sLine);
		}
		fprintf(GCGFile,"\n");
		fprintf(GCGFile,"\n");
		for(i=0;i<m_nNumOfSeq;i++)
		{
			strcpy(sLine,m_vectsSequence[i].c_str());
			fprintf(GCGFile,"%s\n",sLine);
			fprintf(GCGFile,"\n");
		}
		fprintf(GCGFile,"\n");
		fprintf(GCGFile,"\n");
		IntSequences();
		for(i=0;i<m_nNumOfSeq;i++)
		{
			int nSize=m_vectnSequence[i].size();
			for(j=0;j<nSize;j++)
			{
				fprintf(GCGFile,"%2d",m_vectnSequence[i].at(j));
			}
			fprintf(GCGFile,"\n\n");
		}
		fclose(GCGFile);
//	}
}



bool CMAlign::IsChannelName(char  aString[80])
{
	for(int i=0;i<m_nNumOfSeq;i++)
	{
		if(strcmp(aString,m_vectsSeqNames[i].c_str())==0)
		{
			return true;
		}
	}
	return false;
}



void CMAlign::IntSequences()
{
	char aString[5000];
	for(int i=0;i<m_nNumOfSeq;i++)
	{
		vector <int> vectTemp;
		strcpy(aString,m_vectsSequence[i].c_str());
		int nTemp=m_vectsSequence[i].size();
		for(int j=0;j<nTemp;j++)
		{
			for(int k=0;k<21;k++)
			{
				if(m_sAminoAcidNames[k]==aString[j])
				{
					vectTemp.push_back(k);
				}
			}
		}
		m_vectnSequence.push_back(vectTemp);
	}
}



vector <IntVect> CMAlign::Get_nSeq()
{
	return m_vectnSequence;
}

vector <IntVect> CMAlign::GetPositionConversion(int nKey)
{
	if(nKey==0)
		return m_nvvPositionConversion0;
	else
		return m_nvvPositionConversion1;
}

void 	CMAlign::PositionConversion()
{
	char cTemp;


	int i,j;
	int nNumSeq=m_vectnSequence.size();
	int nLength=m_vectnSequence.at(1).size();
	m_nvvPositionConversion0.clear();
	m_nvvPositionConversion1.clear();
	int nResNum;
	for(i=0;i<nNumSeq;i++)
	{
		vector <int> nV0;
		vector <int> nV1;
		for(j=0;j<nLength;j++)
		{
			nV0.push_back(0);
			nV1.push_back(0);
		}
		m_nvvPositionConversion0.push_back(nV0);
		m_nvvPositionConversion1.push_back(nV1);
	}

	for(i=0;i<nNumSeq;i++)
	{
		nResNum=0;
		for(j=0;j<nLength;j++)
		{
			cTemp=m_vectnSequence.at(i)[j];
			m_nvvPositionConversion0.at(i)[nResNum]=j;
			m_nvvPositionConversion1.at(i)[j]=nResNum;
			if(cTemp>64&&cTemp<90||cTemp>96&&cTemp<123)
			{
				nResNum++;
			}
		}
	}
}

