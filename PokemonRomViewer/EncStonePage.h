#pragma once

// CEncStonePage �Ի���

class CEncStonePage : public CEncTabPage
{
	DECLARE_DYNAMIC(CEncStonePage)

public:
	CEncStonePage();   // ��׼���캯��
	virtual ~CEncStonePage();

	void OnConfigChanged(BOOL bRomChanged, BOOL bUILangChanged);
	void TransData(BOOL bToControls);

	void SetFocusedEntry(DWORD dwEncEntryIndex);

// �Ի�������
	enum { IDD = IDD_ROM_ENC_STONE };

protected:
	CComboBox	m_ctrlBrdList[ENC_STONE_ENTRY_COUNT];
	CStatic		m_ctrlImage[ENC_STONE_ENTRY_COUNT];
	CButton		m_ctrlSetBrd[ENC_STONE_ENTRY_COUNT];

	void SetBrdImage(DWORD dwIndex);
	void GetBreed(DWORD dwIndex);
	void SetBreed(DWORD dwIndex);

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void OnCbnSelchangeEncBreedList(UINT uID);
	afx_msg void OnBnClickedEncSetBreed(UINT uID);
	afx_msg void OnSetFocus(UINT uID);
	afx_msg void OnDblClickedIcon(UINT uID);
	DECLARE_MESSAGE_MAP()
};
