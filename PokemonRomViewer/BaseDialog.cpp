// BaseDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PokemonRomViewer.h"
#include "BaseDialog.h"

// CBaseDialog �Ի���

IMPLEMENT_DYNAMIC(CBaseDialog, CDialog)
CBaseDialog::CBaseDialog()
{
}

CBaseDialog::~CBaseDialog()
{
}

void CBaseDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CBaseDialog, CDialog)
END_MESSAGE_MAP()


// CBaseDialog ��Ϣ�������
BOOL CBaseDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	HICON	hIcon;

	if(GetWindowLongPtr(m_hWnd, GWL_STYLE) & WS_DLGFRAME)
	{
		hIcon = AfxGetApp()->LoadIcon(IDI_DIALOG);
		SetIcon(hIcon, TRUE);
		SetIcon(hIcon, FALSE);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CBaseDialog::OnOK()
{
}
