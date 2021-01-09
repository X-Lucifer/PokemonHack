#pragma once


// CMemPmAbilityPage �Ի���

class CMemPmAbilityPage : public CMemPmTabPage
{
	DECLARE_DYNAMIC(CMemPmAbilityPage)

public:
	CMemPmAbilityPage();   // ��׼���캯��
	virtual ~CMemPmAbilityPage();

	void TransData(BOOL bToControls);
	void OnChangeUILang(VOID);

// �Ի�������
	enum { IDD = IDD_MEM_PM_ABILITY };

protected:
	CPokemonCodec *	m_ppc;
	CEdit		m_ctrlBB[6];

	void SetBreedAbilities();

	afx_msg void GetIndv(UINT uID);
	afx_msg void GetBB(UINT uID);
	afx_msg void SetBBSum();

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void OnBnClickedIndvMax();
	afx_msg void OnBnClickedBbMax();
	afx_msg void OnBnClickedBb85();
	afx_msg void OnBnClickedApMax();
	DECLARE_MESSAGE_MAP()
};
