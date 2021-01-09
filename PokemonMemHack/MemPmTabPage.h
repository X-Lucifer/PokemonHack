#pragma once


// CMemPmTabPage �Ի���

class CMemPmTabPage : public CDialog
{
	DECLARE_DYNAMIC(CMemPmTabPage)

public:
	CMemPmTabPage();   // ��׼���캯��
	virtual ~CMemPmTabPage();

	UINT	m_uTemplateId;
	LPCTSTR	m_szPageName;

	virtual void TransData(BOOL bToControls) = 0;
	virtual void OnChangeUILang(VOID) = 0;

// �Ի�������

protected:
	virtual CPokemonCodec * GetPokemonCodec(VOID);
	virtual PokemonStructActive * GetPokemonStructActive(VOID);

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
};
