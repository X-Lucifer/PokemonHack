// PokemonMemHackDlg.h : ͷ�ļ�
//

#pragma once
#include "MemPmPage.h"
#include "MemMiscPage0.h"
#include "MemMiscPage1.h"
#include "MemMiscPage2.h"

// CPokemonMemHackDlg �Ի���
class CPokemonMemHackDlg : public CDialog
{
// ����
public:
	CPokemonMemHackDlg(CWnd* pParent = NULL);	// ��׼���캯��
	~CPokemonMemHackDlg();

// �Ի�������
	enum { IDD = IDD_POKEMONMEMHACK_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON	m_hIcon;

	CMemPmPage		m_pageMemPm;
	CMemMiscPage0	m_pageMisc0;
	CMemMiscPage1	m_pageMisc1;
	CMemMiscPage2	m_pageMisc2;
	CPropertySheet *m_pPropSht;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
};
