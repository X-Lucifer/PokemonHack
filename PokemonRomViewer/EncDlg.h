#pragma once
#include "afxcmn.h"

#include "EncTabPage.h"
#include "EncLandPage.h"	// 1
#include "EncWaterPage.h"	// 2
#include "EncStonePage.h"	// 3
#include "EncFishPage.h"	// 4

#define ENC_PAGE_COUNT	4

// CEncDlg �Ի���

class CEncDlg : public CBaseDialog
{
	DECLARE_DYNAMIC(CEncDlg)

public:
	CEncDlg();   // ��׼���캯��
	virtual ~CEncDlg();

	void OnConfigChanged(BOOL bRomChanged, BOOL bUILangChanged);

	DWORD	m_dwCurSel;		// index in the listctrl
	DWORD	m_dwCurEnc;		// index in enc list
	DWORD	m_dwCurPage;

// �Ի�������
	enum { IDD = IDD_ENC };

protected:
	CListCtrl	m_ctrlEncList;
	CTabCtrl	m_ctrlTab;
	CButton		m_ctrlConfirm;

	DWORD		m_dwSortOrder;
	BOOL		m_bFindEditChanged;

	CEncLandPage	m_pageLand;
	CEncWaterPage	m_pageWater;
	CEncStonePage	m_pageStone;
	CEncFishPage	m_pageFish;
	CEncTabPage *	m_rgpPages[ENC_PAGE_COUNT];

	void ShowTabPage(DWORD dwIndex);
	void RefreshEncList();
	void TransData(BOOL bToControls);
	void SetTabPageNames();
	BOOL FindBreedInEnc(WORD wBreed, DWORD dwEncIndex, DWORD &dwEncType, DWORD &dwEncEntryIndex);

	static INT CALLBACK EncListSortFunc(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort);

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	afx_msg void OnLvnItemchangedEncList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedRefresh();
	afx_msg void OnBnClickedConfirm();
	afx_msg void OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnHdnItemclickEncList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEncFindEdit();
	afx_msg void OnBnClickedEncFind();
	DECLARE_MESSAGE_MAP()
};
