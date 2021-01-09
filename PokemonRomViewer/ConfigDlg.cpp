// ConfigDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PokemonRomViewer.h"
#include "ConfigDlg.h"


// CConfigDlg �Ի���

IMPLEMENT_DYNAMIC(CConfigDlg, CDialog)
CConfigDlg::CConfigDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CConfigDlg::IDD, pParent)
{
	m_dwLang = cfg.dwLang;
	m_dwCount = cfg.dwCount;
	m_szRomPath = cfg.szRomPath;
}

CConfigDlg::~CConfigDlg()
{
}

void CConfigDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CConfigDlg, CDialog)
	ON_BN_CLICKED(IDC_BROWSE, OnBnClickedBrowse)
END_MESSAGE_MAP()


// CConfigDlg ��Ϣ�������

BOOL CConfigDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CheckDlgButton(IDC_UI_CN + m_dwLang, BST_CHECKED);
	CheckDlgButton(IDC_COUNT_0 + m_dwCount, BST_CHECKED);
	SetDlgItemText(IDC_ROM_FILE_PATH, m_szRomPath);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CConfigDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���
	DWORD	dwIndex;

	for(dwIndex = 0; dwIndex < 3; ++dwIndex)
	{
		if(IsDlgButtonChecked(IDC_UI_CN + dwIndex) == BST_CHECKED)
			m_dwLang = dwIndex;

		if(IsDlgButtonChecked(IDC_COUNT_0 + dwIndex) == BST_CHECKED)
			m_dwCount = dwIndex;
	}

	GetDlgItemText(IDC_ROM_FILE_PATH, m_szRomPath);

	CDialog::OnOK();
}

void CConfigDlg::OnBnClickedBrowse()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFileDialog		fd(	TRUE,
						NULL,
						m_szRomPath,
						OFN_HIDEREADONLY | OFN_FILEMUSTEXIST,
						_T("GBA Rom(*.gba)|*.gba|Any File(*.*)|*.*||"),
						this,
						sizeof(OPENFILENAME));

	if(fd.DoModal() == IDOK)
	{
		m_szRomPath = fd.GetPathName();
		SetDlgItemText(IDC_ROM_FILE_PATH, m_szRomPath);
	}
}
