#pragma once


// CBaseDialog �Ի���

class CBaseDialog : public CDialog
{
	DECLARE_DYNAMIC(CBaseDialog)

public:
	CBaseDialog();   // ��׼���캯��
	virtual ~CBaseDialog();

	UINT	m_uTemplateId;

	virtual void OnConfigChanged(BOOL bRomChanged, BOOL bUILangChanged) = 0;

// �Ի�������

protected:

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	DECLARE_MESSAGE_MAP()
};
