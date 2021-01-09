#pragma once


// CBreedMachineLearnPage �Ի���

class CBreedMachineLearnPage : public CBreedTabPage
{
	DECLARE_DYNAMIC(CBreedMachineLearnPage)

public:
	CBreedMachineLearnPage();   // ��׼���캯��
	virtual ~CBreedMachineLearnPage();

	void OnConfigChanged(BOOL bRomChanged, BOOL bUILangChanged);
	void TransData(BOOL bToControls);

// �Ի�������
	enum { IDD = IDD_BREED_MACHINE_LEARN };

protected:
	BYTE *	m_pMachineLearnList;
	WORD *	m_pMachineSkillList;

	CListCtrl	m_ctrlLearnList;
	DWORD		m_dwCurSel;
	DWORD		m_dwCheckedCount;

	enum { order_machine=0, order_checked=1 };
	DWORD	m_dwSortOrder;

	BOOL	m_bIngoreCheckNotify;

	void GetMachineSkillList();
	void GetCurMachineLearnList();

	void RefreshLearnList();
	void SetMachineSkills();
	void SetSkillDesc();
	void SetCheckedCount();
	void SetCheck(DWORD dwItem, BOOL bCheck);

	static INT CALLBACK SortSkillList(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort);

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonClicked(UINT uID);
	afx_msg void OnChangeSortOrder(UINT uID);
	afx_msg void OnLvnItemchangedMlList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMDblclkMlList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnHdnItemclickMlList(NMHDR *pNMHDR, LRESULT *pResult);
	DECLARE_MESSAGE_MAP()
};
