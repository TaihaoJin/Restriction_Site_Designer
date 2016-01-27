// RestrictionTable.h: interface for the CRestrictionTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RESTRICTIONTABLE_H__1FEF0547_8238_499B_9D57_025A8AD7C480__INCLUDED_)
#define AFX_RESTRICTIONTABLE_H__1FEF0547_8238_499B_9D57_025A8AD7C480__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include <vector>
#include "structures_DNA.h"
#include "CodonTable.h"
#include "PointMutationPrimerDlg.h"

using namespace std;


class CRestrictionTable  
{
protected:
	vector <structRestrictionEnzymeNode> m_vstructEnzymeNodes;
	CString m_sCutterFileName;
	bool m_nMatchingBaseTable[123][123];
	void ReadRestrictionSites();
	void InputCutters();
	CString PassString(CString aString);
	int TailNs(structRestrictionEnzymeNode aNode);
	vector <sVect> m_vsPossibleCodons;
	bool PossibleCuttingSite(int nPosition,int j0,int nLength1,CString sRecSeq,int nRecLength,int &nCodonIndex);


public:
	bool MatchingBase(char cA, char cB);
	bool ComplementaryEnzyme(int nIndex1, int nIndex2);
	bool IdenticalRestrictionEnzyme(int nIndex1, int nIndex2);
	CRestrictionTable();
	virtual ~CRestrictionTable();
	vector <structRestrictionSiteNode> GetRestrictionSites(vector <sVect> vsPossibleCodons);
	vector <structRestrictionSiteNode> CRestrictionTable::GetRestrictionSites(CString sSeq);
};

#endif // !defined(AFX_RESTRICTIONTABLE_H__1FEF0547_8238_499B_9D57_025A8AD7C480__INCLUDED_)
