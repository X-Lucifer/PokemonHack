#pragma once


// CBreedTabPage �Ի���

class CBreedTabPage : public CBaseDialog
{
	DECLARE_DYNAMIC(CBreedTabPage)

public:
	CBreedTabPage();   // ��׼���캯��
	virtual ~CBreedTabPage();

	LPCTSTR	m_szPageName;

	virtual void TransData(BOOL bToControls) = 0;

// �Ի�������

protected:
	BreedListEntry *m_pBreed;
	WORD *			m_pBreedAbilities;

	void GetCurrentBreed();

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
};
