#pragma once


// CWaitDlg �Ի���

class CWaitDlg : public CDialog
{
	DECLARE_DYNAMIC(CWaitDlg)

public:
	CWaitDlg();   // ��׼���캯��
	virtual ~CWaitDlg();

	void BeginWait(DWORD dwRange);
	void IncStep();

// �Ի�������
	enum { IDD = IDD_WAIT };

protected:
	CProgressCtrl	m_ctrlProg;
	UINT_PTR		m_uTimer;
	DWORD			m_dwRange;

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnTimer(UINT nIDEvent);
	DECLARE_MESSAGE_MAP()
};
