#if !defined(AFX_EVLNODE_H__829A080D_5FE1_11D4_83DE_00C04F200C6A__INCLUDED_)
#define AFX_EVLNODE_H__829A080D_5FE1_11D4_83DE_00C04F200C6A__INCLUDED_
#include <vector>

using namespace std;

typedef vector <float> FVect;
typedef vector <int> IntVect;
typedef vector <CString> sVect;
struct structRestrictionEnzymeNode{
	CString sName;
	int nUnitSize; //"Size of recognition sequence"
	int nMatchSize; //"size without N's"
	CString sRecSeq; //"Recognition sequence"
	int nCutSize; //"Cut site on the plus strand"
	int nOverhang; //"Overhang"
	int nPalindromic; //"1 if it's panlidromic, 0 if not."
	int nSemicolon; //"1 if it's from a REBASE record that has a semicolon in front, 0 if not."
	int nNumSciz; //"Number of isoscizomers"
	vector <CString> vsScizs; //"Names of isoscizomers"
	int nNumCompanies; //"Number of companies selling this enzyme"
	vector <CString> vsCompanies; //"Company letters"
	int nNumRefs; //"Number of references"
	vector <int> vnRefs; //"Reference numbers"
	int nTailNs; //Number of N's at the end
	vector  <int> nvCompEnzymes;  //Indexes of enzymes create the same ends after cuttings
	vector  <int> nvIdenticalEnzymes;  //Indexes of enzymes that have the same RecSequence
};

struct structRestrictionSiteNode{
	int nCuttingPosition; //>=1;The enzyme cuts between base n and n+1, n=nCuttingPosition
	structRestrictionEnzymeNode strEnzymeNode;
	CString sOriginalSeq;
	CString sNewSeq;
	int nNumMutations;  //Number of silent mutations to create the restriction site
	int nNumCuttings0;  //Number of cuttings by the same enzyme without mutations
	int nNumCuttings1;  //Number of cuttings by the same enzyme incluing mutations.
};

struct structCodonNode{
	char cCodon[4];
	int nCodon[3];
	char cAA1;
	char sAA3[4];
};

struct structCodonUsageNode{
	vector <IntVect> nvvAAToCodon;
	vector <FVect> fvvCodonUsage;	
};


#endif // !defined(AFX_EVLNODE_H__829A080D_5FE1_11D4_83DE_00C04F200C6A__INCLUDED_)

