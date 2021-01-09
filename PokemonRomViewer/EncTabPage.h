#pragma once


// CEncTabPage �Ի���

class CEncTabPage : public CBaseDialog
{
	DECLARE_DYNAMIC(CEncTabPage)

public:
	CEncTabPage();   // ��׼���캯��
	virtual ~CEncTabPage();

	LPCTSTR	m_szPageName;
	DWORD	m_dwFocusedEntry;

	virtual void TransData(BOOL bToControls) = 0;
	virtual void SetFocusedEntry(DWORD dwEncEntryIndex) = 0;

// �Ի�������

protected:
	EncLandList *	m_pLandList;
	EncWaterList *	m_pWaterList;
	EncStoneList *	m_pStoneList;
	EncFishList *	m_pFishList;
	BYTE *			m_pAnnoonList;

	void GetCurrentEncLists();

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
};
