#pragma once
#include "afxwin.h"


// CBreedTypePage �Ի���

class CBreedTypePage : public CBreedTabPage
{
	DECLARE_DYNAMIC(CBreedTypePage)

public:
	CBreedTypePage();   // ��׼���캯��
	virtual ~CBreedTypePage();

	void OnConfigChanged(BOOL bRomChanged, BOOL bUILangChanged);
	void TransData(BOOL bToControls);

// �Ի�������
	enum { IDD = IDD_BREED_TYPE };

protected:
	CListBox	m_ctrlTypeList[2];
	CListBox	m_ctrlEGList[2];

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
};
