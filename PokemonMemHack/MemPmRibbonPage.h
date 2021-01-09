#pragma once


// CMemPmRibbonPage �Ի���

class CMemPmRibbonPage : public CMemPmTabPage
{
	DECLARE_DYNAMIC(CMemPmRibbonPage)

public:
	CMemPmRibbonPage();   // ��׼���캯��
	virtual ~CMemPmRibbonPage();

	void TransData(BOOL bToControls);
	void OnChangeUILang(VOID);

// �Ի�������
	enum { IDD = IDD_MEM_PM_RIBBON };

protected:
	CPokemonCodec *	m_ppc;

	void SetRibbons();
	void GetRibbons();

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void OnClickRadioButtons(UINT uID);
	afx_msg void OnBnClickedRibbons32();
	afx_msg void OnBnClickedRibbons25();
	afx_msg void OnBnClickedRibbons0();
	DECLARE_MESSAGE_MAP()
};
