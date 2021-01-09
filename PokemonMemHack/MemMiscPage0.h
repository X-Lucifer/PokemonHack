#pragma once
#include "afxwin.h"


// CMemMiscPage0 �Ի���

class CMemMiscPage0 : public CPropertyPage
{
	DECLARE_DYNAMIC(CMemMiscPage0)

public:
	CMemMiscPage0();
	virtual ~CMemMiscPage0();

	VOID OnChangeUILang(VOID);

// �Ի�������
	enum { IDD = IDD_MEM_MISC0 };

protected:
	BOOL		m_bEnableText;
	CEdit		m_ctrlTrainerName;

	BOOL SetPlayerName(VOID);

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void OnBnClickedRefresh();
	afx_msg void OnBnClickedConfirm();
	afx_msg void OnBnClickedEnableText();
	DECLARE_MESSAGE_MAP()
};
