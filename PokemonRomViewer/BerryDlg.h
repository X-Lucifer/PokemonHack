#pragma once
#include "afxcmn.h"


// CBerryDlg �Ի���

class CBerryDlg : public CBaseDialog
{
	DECLARE_DYNAMIC(CBerryDlg)

public:
	CBerryDlg();   // ��׼���캯��
	virtual ~CBerryDlg();

	DWORD	m_dwCurSel;
	DWORD	m_dwCurBerry;

	void OnConfigChanged(BOOL bRomChanged, BOOL bUILangChanged);
	void SetCurSkill(WORD wSkill);

// �Ի�������
	enum { IDD = IDD_BEERY };

protected:
	CListCtrl m_ctrlBerryList;

	void SetBerryListItem(DWORD dwIndex);
	void SetBerry();
	void GetBerry();

	static INT CALLBACK SortBerries(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort);

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedRefresh();
	afx_msg void OnBnClickedConfirm();
	afx_msg void OnHdnItemclickBerryBerryList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemchangedBerryBerryList(NMHDR *pNMHDR, LRESULT *pResult);
	DECLARE_MESSAGE_MAP()
};
