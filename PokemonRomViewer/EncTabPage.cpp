// EncTabPage.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PokemonRomViewer.h"
#include "EncTabPage.h"


// CEncTabPage �Ի���

IMPLEMENT_DYNAMIC(CEncTabPage, CBaseDialog)
CEncTabPage::CEncTabPage()
{
	m_pLandList = NULL;
	m_pWaterList = NULL;
	m_pStoneList = NULL;
	m_pFishList = NULL;
	m_pAnnoonList = NULL;
	m_dwFocusedEntry = -1;
}

CEncTabPage::~CEncTabPage()
{
}

void CEncTabPage::DoDataExchange(CDataExchange* pDX)
{
	CBaseDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CEncTabPage, CBaseDialog)
END_MESSAGE_MAP()


// CEncTabPage ��Ϣ�������
void CEncTabPage::OnCancel()
{
}

void CEncTabPage::GetCurrentEncLists()
{
	DWORD	dwEncIndex = theApp.m_dlgEnc.m_dwCurEnc;

	m_pLandList = rom.GetEncLandList(dwEncIndex);
	m_pWaterList = rom.GetEncWaterList(dwEncIndex);
	m_pStoneList = rom.GetEncStoneList(dwEncIndex);
	m_pFishList = rom.GetEncFishList(dwEncIndex);

	m_pAnnoonList = rom.GetAnnoonEncList(dwEncIndex);
}
