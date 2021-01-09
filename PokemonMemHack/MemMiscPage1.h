#pragma once


// CMemMiscPage1 �Ի���

class CMemMiscPage1 : public CPropertyPage
{
	DECLARE_DYNAMIC(CMemMiscPage1)

public:
	CMemMiscPage1();
	virtual ~CMemMiscPage1();

	VOID OnChangeUILang(VOID);

// �Ի�������
	enum { IDD = IDD_MEM_MISC1 };

protected:
	BOOL		m_bCreated;
	CComboBox	m_ctrlItemList;
	CFont		m_Font;
	CStatic *	m_Static;

	afx_msg void SetItemDesc();

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnBnClickedAddItem();
	afx_msg void OnBnClickedIncItems();
	afx_msg void OnBnClickedGivePokeballs();
	afx_msg void OnBnClickedGiveMachines();
	afx_msg void OnBnClickedGiveBerries();
	afx_msg void OnBnClickedGivePokeblock();
	afx_msg void OnBnClickedGiveDecorates();
	afx_msg void OnBnClickedDropLastKeyitem();
	afx_msg void OnBnClickedEnableAllTickets();
	afx_msg void OnBnClickedAddItemBp50();
	afx_msg void OnBnClickedAddItemBp60();
	afx_msg void OnBnClickedMaxViewInBp();
	DECLARE_MESSAGE_MAP()
};
