#pragma once

// CSkillDlg �Ի���

class CSkillDlg : public CBaseDialog
{
	DECLARE_DYNAMIC(CSkillDlg)

public:
	CSkillDlg();   // ��׼���캯��
	virtual ~CSkillDlg();

	WORD	m_wCurSel;
	WORD	m_wCurSkill;

	void OnConfigChanged(BOOL bRomChanged, BOOL bUILangChanged);
	void SetCurSkill(WORD wSkill);

// �Ի�������
	enum { IDD = IDD_SKILL };

protected:
	CListCtrl	m_ctrlSkillList;
	CListBox	m_ctrlTargetList;
	CListBox	m_ctrlTypeList;
	CButton		m_ctrlConfirm;

	static INT CALLBACK SortSkills(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort);

	void SetSkillListItem(WORD wIndex);

	void SetSkill();
	void GetSkill();
	void SetSkillDesc();

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	afx_msg void OnHdnItemclickSklSkillList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemchangedSklSkillList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedRefresh();
	afx_msg void OnBnClickedConfirm();
	DECLARE_MESSAGE_MAP()
};
