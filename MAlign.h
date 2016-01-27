// MAlign.h: interface for the CMAlign class.

//

//////////////////////////////////////////////////////////////////////



#if !defined(AFX_MALIGN_H__E5274611_F36A_4466_9119_8CEC45E9746A__INCLUDED_)

#define AFX_MALIGN_H__E5274611_F36A_4466_9119_8CEC45E9746A__INCLUDED_



#if _MSC_VER > 1000

#pragma once

#endif // _MSC_VER > 1000

#include "stdafx.h"

#include <string>

#include <vector>

using namespace std;

typedef vector <int> IntVect;



class CMAlign  

{

public:
	void IntSequences();
	void OutputMAlign();
	CMAlign();
	void ReadMAlign();
	virtual ~CMAlign();
	vector <IntVect> CMAlign::GetPositionConversion(int nKey);
	vector <IntVect> Get_nSeq();
private:


protected:

	bool IsChannelName(char aString[80]);
	CString m_sMAlignFileName;
	int m_nSeqLength;
	int m_nNumOfSeq;
	vector <string> m_vectsSeqNames;
	vector <string> m_vectsSequence;
	vector <IntVect> m_vectnSequence;
	char m_sAminoAcidNames[21];
	void PositionConversion();
	vector <IntVect> m_nvvPositionConversion0;  //The element m_nvvPositionCovertion0.at(i)[j] stores the 
											   //global position of the j-th residue of the i-th sequence.
	vector <IntVect> m_nvvPositionConversion1;  //The element m_nvvPositionCovertion1.at(i)[j] stores the 
											   //the position of the residue of the i-th sequence which is 
											   //is located at the global position j. The element will be 
											   //the position of the previous nongap residue if the i-th 
											   //sequence has a gap in the global position j.
};



#endif // !defined(AFX_MALIGN_H__E5274611_F36A_4466_9119_8CEC45E9746A__INCLUDED_)

