#pragma once
#include "afxwin.h"


// CMemPmSkillPage �Ի���

class CMemPmSkillPage : public CMemPmTabPage
{
	DECLARE_DYNAMIC(CMemPmSkillPage)

public:
	CMemPmSkillPage();   // ��׼���캯��
	virtual ~CMemPmSkillPage();

	void TransData(BOOL bToControls);
	void OnChangeUILang(VOID);

// �Ի�������
	enum { IDD = IDD_MEM_PM_SKILL };

protected:
	CPokemonCodec *	m_ppc;
	//CComboBox	m_ctrlSkillList[4];
	CSkillComboBox	m_ctrlSkillList[4];
	CEdit		m_ctrlPP[4];
	CComboBox	m_ctrlPPBoostList[4];
	//CListBox	m_ctrlLegalSkillList;
	CSkillListBox m_ctrlLegalSkillList;
	BOOL	m_bROMLegelSkill;

	void SetSkillLists(BOOL bChangeLang, BOOL bNeedSort);
	void SetLegalSkillList(WORD wBreed);

	afx_msg void SetSkillDesc(UINT uID);
	afx_msg void SetSkillFromLegalSkillList(UINT uID);

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	afx_msg void OnStnDblclickPpBoostAll();
	afx_msg void OnLbnSelchangeLegalSkillList();
	afx_msg void OnStnDblclickMemPpMax();
	afx_msg void OnStnDblclickLegelSkillLabel();
	DECLARE_MESSAGE_MAP()
};
