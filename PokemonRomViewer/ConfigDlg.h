#pragma once


// CConfigDlg �Ի���

class CConfigDlg : public CDialog
{
	DECLARE_DYNAMIC(CConfigDlg)

public:
	CConfigDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CConfigDlg();

	DWORD		m_dwLang;
	DWORD		m_dwCount;
	CString		m_szRomPath;

// �Ի�������
	enum { IDD = IDD_CONFIG };

protected:

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnBnClickedBrowse();
	DECLARE_MESSAGE_MAP()
};
