// CodonTable.h: interface for the CCodonTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CODONTABLE_H__4E9A5811_F166_4CCC_84E0_892B1643239D__INCLUDED_)
#define AFX_CODONTABLE_H__4E9A5811_F166_4CCC_84E0_892B1643239D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "structures_DNA.h"
class CCodonTable  
{
public:
	void OutputCodonUsage();
	void MakeCodonUsage(CString sNaSeq0);
	structCodonUsageNode GetCodonUsage(CString sSeq0);
	IntVect ReverseStrand(IntVect nvNASeq);
	CString StrNASeq(IntVect nvNASequence);
	int Translate(int nCodon0[]);
	IntVect GetCodon(int nIndex);
	void GetCodon(int nIndex, int* pnCodon);
	//This function returns the integer form of the codon corresponding to nIndex
	vector <IntVect> Mutation(int nCodon0[3],char cAA,bool bCodonUsage);
	//This function returns all codons (integer form) coding for the amino acid cAA. 
	//The codons are sorted in assending order of the number of n. a. differ from the original codon nCodon0
	int CodonIndex(int nCodon[3]);
	//This function returns the index of the codon nCodon in the codon table
	void AAToCodon();
		//Sorting the codon table according to the coded amino acids and stored in m_nvvAAToCodon (ascending order of 
		//single letter amino acids
	int IntNA(char cNA);
		//Returning the indeces of NA
	int IntAA(char cAA);
		//Returning the indeces of AA
	int IntAA(char sAA[]);
		//Returning the indeces of AA (input the three letter form of AA names
	vector <CString> CCodonTable::Mutation(int nCodon0[3],char cAA, int nKey);
	vector <CString> CCodonTable::Mutation(int nCodon0[3],int nAA2, int nKey);
	//including the original codon when nKey==0
	vector <int> IntAASeq(CString sSeq0);
		//Returning the integer form of the AA sequence (input the one letter form of AA sequence)
	vector <int> IntNASeq(CString sSeq0);
		//Returning the integer form of the NA sequence.
	CCodonTable();
	virtual ~CCodonTable();
protected:
	CString GetStrCodon(int nIndex);
	void BubbleSort(int* pnA, int* pnB, int nSize);
		//Sort the contents of pnA and pnB in the ascending order of pnA.
	int NADiff(int nCodon1, int nCodon2);
		//Returning the number of different NA in the codons corresponding to nCodon1 and nCodon2
	structCodonNode m_arCodonNodes[65];
	char m_sAA1[25];
	char m_sAA3[73];
	char m_sNA[5];
	vector <IntVect> m_nvvAAToCodon;
	structCodonUsageNode m_structCodonUsage;
};

#endif // !defined(AFX_CODONTABLE_H__4E9A5811_F166_4CCC_84E0_892B1643239D__INCLUDED_)
