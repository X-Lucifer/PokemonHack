#pragma once


// CBreedDeriveLearnPage �Ի���

class CBreedDeriveLearnPage : public CBreedTabPage
{
	DECLARE_DYNAMIC(CBreedDeriveLearnPage)

public:
	CBreedDeriveLearnPage();   // ��׼���캯��
	virtual ~CBreedDeriveLearnPage();

	void OnConfigChanged(BOOL bRomChanged, BOOL bUILangChanged);
	void TransData(BOOL bToControls);

// �Ի�������
	enum { IDD = IDD_BREED_DERIVE_LEARN };

protected:
	WORD *	m_pDeriveLearnList;
	DWORD	m_dwDeriveLearnCount;
	void GetCurDeriveLearnList();

	CListCtrl	m_ctrlLearnList;
	CComboBox	m_ctrlSkillList;
	DWORD		m_dwCurSel;

	void RefreshLearnList();
	void RefreshSkillList();
	void SetSkillDesc();
	void SetSkill();
	void GetSkills();

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	afx_msg void OnLvnItemchangedDlList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMDblclkDlList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedDlFromSkillDlg();
	afx_msg void OnBnClickedDlSetSkill();
	DECLARE_MESSAGE_MAP()
};
