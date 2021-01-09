// BreedTypePage.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PokemonRomViewer.h"
#include "BreedTypePage.h"


// CBreedTypePage �Ի���

IMPLEMENT_DYNAMIC(CBreedTypePage, CBreedTabPage)
CBreedTypePage::CBreedTypePage()
{
	m_uTemplateId = CBreedTypePage::IDD;
}

CBreedTypePage::~CBreedTypePage()
{
}

void CBreedTypePage::DoDataExchange(CDataExchange* pDX)
{
	CBreedTabPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TYPE_LIST0, m_ctrlTypeList[0]);
	DDX_Control(pDX, IDC_TYPE_LIST1, m_ctrlTypeList[1]);
	DDX_Control(pDX, IDC_EG_LIST0, m_ctrlEGList[0]);
	DDX_Control(pDX, IDC_EG_LIST1, m_ctrlEGList[1]);
}


BEGIN_MESSAGE_MAP(CBreedTypePage, CBreedTabPage)
END_MESSAGE_MAP()


// CBreedTypePage ��Ϣ�������
void CBreedTypePage::OnConfigChanged(BOOL bRomChanged, BOOL bUILangChanged)
{
	if(bRomChanged)
		TransData(TRUE);
}

void CBreedTypePage::TransData(BOOL bToControls)
{
	GetCurrentBreed();
	if(m_pBreed == NULL)
		return;

	if(bToControls)
	{
		m_ctrlTypeList[0].SetCurSel(m_pBreed->bType1);
		m_ctrlTypeList[1].SetCurSel(m_pBreed->bType2);
		m_ctrlEGList[0].SetCurSel(m_pBreed->bEggGroup1);
		m_ctrlEGList[1].SetCurSel(m_pBreed->bEggGroup2);
	}
	else
	{
		m_pBreed->bType1 = m_ctrlTypeList[0].GetCurSel();
		m_pBreed->bType2 = m_ctrlTypeList[1].GetCurSel();
		m_pBreed->bEggGroup1 = m_ctrlEGList[0].GetCurSel();
		m_pBreed->bEggGroup2 = m_ctrlEGList[1].GetCurSel();
	}
}


BOOL CBreedTypePage::OnInitDialog()
{
	CBreedTabPage::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	DWORD	dwIndex;
	CString	szText;

	for(dwIndex = 0; dwIndex < dwTypesCount; ++dwIndex)
	{
		szText.Format(_T("%02lX:%s"), dwIndex, szTypes[dwIndex]);
		m_ctrlTypeList[0].AddString(szText);
		m_ctrlTypeList[1].AddString(szText);
	}
	m_ctrlTypeList[0].SetCurSel(0);
	m_ctrlTypeList[1].SetCurSel(0);

	for(dwIndex = 0; dwIndex < dwEggGroupsCount; ++dwIndex)
	{
		szText.Format(_T("%02lX:%s"), dwIndex, szEggGroups[dwIndex]);
		m_ctrlEGList[0].AddString(szText);
		m_ctrlEGList[1].AddString(szText);
	}
	m_ctrlEGList[0].SetCurSel(0);
	m_ctrlEGList[1].SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
