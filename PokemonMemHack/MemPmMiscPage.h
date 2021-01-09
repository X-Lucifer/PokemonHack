#pragma once
#include "afxwin.h"


// CMemPmMiscPage �Ի���

class CMemPmMiscPage : public CMemPmTabPage
{
	DECLARE_DYNAMIC(CMemPmMiscPage)

public:
	CMemPmMiscPage();   // ��׼���캯��
	virtual ~CMemPmMiscPage();

	void TransData(BOOL bToControls);
	void OnChangeUILang(VOID);

// �Ի�������
	enum { IDD = IDD_MEM_PM_MISC };

protected:
	CPokemonCodec *	m_ppc;
	CComboBox		m_ctrlPokeballList;
	CComboBox		m_ctrlAreaList;
	CComboBox		m_ctrlGameVersionList;
	CButton			m_ctrlMark[4];
	HBITMAP			m_hMark[4];

	CButton			m_ctrlDecode;
	CButton			m_ctrlEncode;
	CButton			m_ctrlReset;
	CEdit			m_ctrlAddress;

	void SetPmRear();
	void GetPmRear();
	void SetAddress();

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedDecode();
	afx_msg void OnBnClickedEncode();
	afx_msg void OnBnClickedReset();
	afx_msg void OnBnClickedAutoCalc();
	afx_msg void OnStnDblclickSecret();
	DECLARE_MESSAGE_MAP()
};
