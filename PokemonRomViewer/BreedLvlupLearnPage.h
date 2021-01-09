#pragma once


// CBreedLvlupLearnPage �Ի���

class CBreedLvlupLearnPage : public CBreedTabPage
{
	DECLARE_DYNAMIC(CBreedLvlupLearnPage)

public:
	CBreedLvlupLearnPage();   // ��׼���캯��
	virtual ~CBreedLvlupLearnPage();

	void OnConfigChanged(BOOL bRomChanged, BOOL bUILangChanged);
	void TransData(BOOL bToControls);

// �Ի�������
	enum { IDD = IDD_BREED_LVLUP_LEARN };

protected:
	LvlupLearnListEntry	*	m_pLvlupLearnList;
	DWORD					m_dwLvlupLearnCount;
	void GetCurLvlLearnList();

	CListCtrl	m_ctrlLearnList;
	CComboBox	m_ctrlSkillList;
	DWORD		m_dwCurSel;

	void RefreshLearnList();
	void RefreshSkillList();
	void SetSkillDesc();
	void SetSkill();
	void GetSkills();

	static INT CALLBACK SortSkillList(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort);

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	afx_msg void OnLvnItemchangedLulList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMDblclkLulList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnHdnItemclickLulList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedLulFromSkillDlg();
	afx_msg void OnBnClickedLulSetSkill();
	DECLARE_MESSAGE_MAP()
};
