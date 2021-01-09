// BerryDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PokemonRomViewer.h"
#include "BerryDlg.h"

#define FIRST_BERRY_IN_ITEM_LIST	(0x085)

struct BerrySortParam
{
	INT		iSubItem;
	BOOL	bAscending;
};

// CBerryDlg �Ի���

IMPLEMENT_DYNAMIC(CBerryDlg, CBaseDialog)
CBerryDlg::CBerryDlg()
{
	m_uTemplateId = CBerryDlg::IDD;
	m_dwCurSel = -1;
	m_dwCurBerry = -1;
}

CBerryDlg::~CBerryDlg()
{
}

void CBerryDlg::DoDataExchange(CDataExchange* pDX)
{
	CBaseDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BERRY_BERRY_LIST, m_ctrlBerryList);
}

BEGIN_MESSAGE_MAP(CBerryDlg, CBaseDialog)
	ON_BN_CLICKED(IDC_REFRESH, OnBnClickedRefresh)
	ON_BN_CLICKED(IDC_CONFIRM, OnBnClickedConfirm)
	ON_NOTIFY(HDN_ITEMCLICK, 0, OnHdnItemclickBerryBerryList)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_BERRY_BERRY_LIST, OnLvnItemchangedBerryBerryList)
END_MESSAGE_MAP()

// CBerryDlg ��Ϣ�������

BOOL CBerryDlg::OnInitDialog()
{
	CBaseDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	DWORD	dwBerry;
	CString	szText;

	m_ctrlBerryList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_HEADERDRAGDROP);
	m_ctrlBerryList.InsertColumn(0,		_T("���"),			LVCFMT_LEFT, 40,	0);
	m_ctrlBerryList.InsertColumn(1,		_T("����"),			LVCFMT_LEFT, 100,	1);
	m_ctrlBerryList.InsertColumn(2,		_T("Ӳ��"),			LVCFMT_LEFT, 40,	2);
	m_ctrlBerryList.InsertColumn(3,		_T("��С"),			LVCFMT_LEFT, 40,	3);
	m_ctrlBerryList.InsertColumn(4,		_T("���"),			LVCFMT_LEFT, 40,	4);
	m_ctrlBerryList.InsertColumn(5,		_T("����"),			LVCFMT_LEFT, 40,	5);
	m_ctrlBerryList.InsertColumn(6,		_T("��ʱ"),			LVCFMT_LEFT, 40,	6);
	m_ctrlBerryList.InsertColumn(7,		_T("��"),			LVCFMT_LEFT, 30,	7);
	m_ctrlBerryList.InsertColumn(8,		_T("ɬ"),			LVCFMT_LEFT, 30,	8);
	m_ctrlBerryList.InsertColumn(9,		_T("��"),			LVCFMT_LEFT, 30,	9);
	m_ctrlBerryList.InsertColumn(10,	_T("��"),			LVCFMT_LEFT, 30,	10);
	m_ctrlBerryList.InsertColumn(11,	_T("��"),			LVCFMT_LEFT, 30,	11);
	m_ctrlBerryList.InsertColumn(12,	_T("��"),			LVCFMT_LEFT, 30,	12);
	m_ctrlBerryList.InsertColumn(13,	_T("˵��"),			LVCFMT_LEFT, 300,	13);

	for(dwBerry = 0; dwBerry < BERRY_COUNT; ++dwBerry)
	{
		m_ctrlBerryList.InsertItem(dwBerry, _T(""));
		m_ctrlBerryList.SetItemData(dwBerry, dwBerry);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CBerryDlg::SetBerryListItem(DWORD dwIndex)
{
	DWORD	dwBerry;
	CString	szText;
	BerryListEntry *pBerry = NULL;

	dwBerry = (DWORD)(m_ctrlBerryList.GetItemData(dwIndex));
	pBerry = rom.GetBerryListEntry(dwBerry);

	// Ӳ��
	szText.Format(_T("%hu"), pBerry->bFirm);
	m_ctrlBerryList.SetItemText(dwIndex, 2, szText);

	// ��С
	szText.Format(_T("%hu"), pBerry->bSize);
	m_ctrlBerryList.SetItemText(dwIndex, 3, szText);

	// ��С����
	szText.Format(_T("%hu"), pBerry->bMin);
	m_ctrlBerryList.SetItemText(dwIndex, 4, szText);

	// ������
	szText.Format(_T("%hu"), pBerry->bMax);
	m_ctrlBerryList.SetItemText(dwIndex, 5, szText);

	// ÿ�׶κ�ʱ
	szText.Format(_T("%hu"), pBerry->bHoursPerStage);
	m_ctrlBerryList.SetItemText(dwIndex, 6, szText);

	// ��
	szText.Format(_T("%hu"), pBerry->bSpicy);
	m_ctrlBerryList.SetItemText(dwIndex, 7, szText);

	// ɬ
	szText.Format(_T("%hu"), pBerry->bDry);
	m_ctrlBerryList.SetItemText(dwIndex, 8, szText);

	// ��
	szText.Format(_T("%hu"), pBerry->bSweet);
	m_ctrlBerryList.SetItemText(dwIndex, 9, szText);

	// ��
	szText.Format(_T("%hu"), pBerry->bBitter);
	m_ctrlBerryList.SetItemText(dwIndex, 10, szText);

	// ��
	szText.Format(_T("%hu"), pBerry->bSour);
	m_ctrlBerryList.SetItemText(dwIndex, 11, szText);

	// ��
	szText.Format(_T("%hu"), pBerry->bFeel);
	m_ctrlBerryList.SetItemText(dwIndex, 12, szText);
}

void CBerryDlg::OnConfigChanged(BOOL bRomChanged, BOOL bUILangChanged)
{
	DWORD	dwIndex, dwBerry;
	CString	szText;
	LPCTSTR	szFmt22[3] = { _T("%-2lu"), _T("%-2lu"), _T("%02lX") };
	BerryListEntry *pBerry = NULL;

	if(!rom.m_bOpened)
		return;

	if(bUILangChanged)
	{
		for(dwIndex = 0; dwIndex < BERRY_COUNT; ++dwIndex)
		{
			dwBerry = (DWORD)(m_ctrlBerryList.GetItemData(dwIndex));

			// ���
			szText.Format(szFmt22[cfg.dwCount], dwBerry + 1);
			m_ctrlBerryList.SetItemText(dwBerry, 0, szText);

			// ����
			m_ctrlBerryList.SetItemText(dwBerry, 1, cfg.pItemNameList[FIRST_BERRY_IN_ITEM_LIST + dwBerry].rgszText[cfg.dwLang]);

			// ˵��
			m_ctrlBerryList.SetItemText(dwBerry, 13, cfg.pItemDescList[FIRST_BERRY_IN_ITEM_LIST + dwBerry].rgszText[cfg.dwLang]);
		}
	}

	if(bRomChanged)
	{
		for(dwIndex = 0; dwIndex < BERRY_COUNT; ++dwIndex)
		{
			SetBerryListItem(dwIndex);
		}

		if(m_dwCurSel >= BERRY_COUNT)
			m_ctrlBerryList.SetItemState(0, -1, LVIS_SELECTED | LVIS_FOCUSED);
	}
}

INT CALLBACK CBerryDlg::SortBerries(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
	INT		iResult = 0;
	BerrySortParam *pBSP = reinterpret_cast<BerrySortParam *>(lParamSort);
	BerryListEntry *pBerry0 = NULL;
	BerryListEntry *pBerry1 = NULL;

	if(pBSP && rom.m_bOpened)
	{
		pBerry0 = rom.GetBerryListEntry((DWORD)(lParam1));
		pBerry1 = rom.GetBerryListEntry((DWORD)(lParam2));

		switch(pBSP->iSubItem)
		{
		case 0:		// ���
			iResult = (INT)(lParam1 - lParam2);
			break;

		//case 1:		// ����
		//	break;

		case 2:		// Ӳ��
			iResult = (INT)(pBerry0->bFirm - pBerry1->bFirm);
			break;

		case 3:		// ��С
			iResult = (INT)(pBerry0->bSize - pBerry1->bSize);
			break;

		case 4:		// ��С����
			iResult = (INT)(pBerry0->bMin - pBerry1->bMin);
			break;

		case 5:		// ������
			iResult = (INT)(pBerry0->bMax - pBerry1->bMax);
			break;

		case 6:		// ÿ�׶κ�ʱ
			iResult = (INT)(pBerry0->bHoursPerStage - pBerry1->bHoursPerStage);
			break;

		case 7:		// ��
			iResult = (INT)(pBerry0->bSpicy - pBerry1->bSpicy);
			break;

		case 8:		// ɬ
			iResult = (INT)(pBerry0->bDry - pBerry1->bDry);
			break;

		case 9:		// ��
			iResult = (INT)(pBerry0->bSweet - pBerry1->bSweet);
			break;

		case 10:	// ��
			iResult = (INT)(pBerry0->bBitter - pBerry1->bBitter);
			break;

		case 11:	// ��
			iResult = (INT)(pBerry0->bSour - pBerry1->bSour);
			break;

		case 12:	// ��
			iResult = (INT)(pBerry0->bFeel - pBerry1->bFeel);
			break;
		}

		if(!pBSP->bAscending)
			iResult = -iResult;
	}

	return iResult;
}

void CBerryDlg::OnBnClickedRefresh()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(!rom.ReadBerryList())
	{
		AfxMessageBox(IDS_ERR_ROM_READ);
	}
	else
	{
		OnConfigChanged(TRUE, FALSE);
		SetBerry();
	}
}

void CBerryDlg::OnBnClickedConfirm()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetBerry();

	if(!rom.SaveBerryList())
	{
		AfxMessageBox(IDS_ERR_ROM_READ);
	}
}

void CBerryDlg::SetBerry()
{
	CString	szText;
	BerryListEntry *pBerry = NULL;

	if(rom.m_bOpened && m_dwCurBerry < BERRY_COUNT)
	{
		pBerry = rom.GetBerryListEntry(m_dwCurBerry);

		// Ӳ��
		szText.Format(_T("%hu"), pBerry->bFirm);
		SetDlgItemText(IDC_BERRY_FIRM, szText);

		// ��С
		szText.Format(_T("%hu"), pBerry->bSize);
		SetDlgItemText(IDC_BERRY_SIZE, szText);

		// ��С����
		szText.Format(_T("%hu"), pBerry->bMin);
		SetDlgItemText(IDC_BERRY_MIN, szText);

		// ������
		szText.Format(_T("%hu"), pBerry->bMax);
		SetDlgItemText(IDC_BERRY_MAX, szText);

		// ÿ�׶κ�ʱ
		szText.Format(_T("%hu"), pBerry->bHoursPerStage);
		SetDlgItemText(IDC_BERRY_HOURS_PER_STAGE, szText);

		// ��
		szText.Format(_T("%hu"), pBerry->bSpicy);
		SetDlgItemText(IDC_BERRY_SPICY, szText);

		// ɬ
		szText.Format(_T("%hu"), pBerry->bDry);
		SetDlgItemText(IDC_BERRY_DRY, szText);

		// ��
		szText.Format(_T("%hu"), pBerry->bSweet);
		SetDlgItemText(IDC_BERRY_SWEET, szText);

		// ��
		szText.Format(_T("%hu"), pBerry->bBitter);
		SetDlgItemText(IDC_BERRY_BITTER, szText);

		// ��
		szText.Format(_T("%hu"), pBerry->bSour);
		SetDlgItemText(IDC_BERRY_SOUR, szText);

		// ��
		szText.Format(_T("%hu"), pBerry->bFeel);
		SetDlgItemText(IDC_BERRY_FEEL, szText);
	}
}

void CBerryDlg::GetBerry()
{
	CString	szText;
	BerryListEntry *pBerry = NULL;

	if(rom.m_bOpened && m_dwCurBerry < BERRY_COUNT)
	{
		pBerry = rom.GetBerryListEntry(m_dwCurBerry);

		// Ӳ��
		GetDlgItemText(IDC_BERRY_FIRM, szText);
		pBerry->bFirm = (BYTE)(min(_tcstoul(szText, 0, 0), 0xFF));
		if(pBerry->bFirm > 5)
			pBerry->bFirm = 5;

		// ��С
		GetDlgItemText(IDC_BERRY_SIZE, szText);
		pBerry->bSize = (BYTE)(min(_tcstoul(szText, 0, 0), 0xFF));

		// ��С����
		GetDlgItemText(IDC_BERRY_MIN, szText);
		pBerry->bMin = (BYTE)(min(_tcstoul(szText, 0, 0), 0xFF));

		// ������
		GetDlgItemText(IDC_BERRY_MAX, szText);
		pBerry->bMax = (BYTE)(min(_tcstoul(szText, 0, 0), 0xFF));
		if(pBerry->bMax < pBerry->bMin)
			pBerry->bMax = pBerry->bMin;

		// ÿ�׶κ�ʱ
		GetDlgItemText(IDC_BERRY_HOURS_PER_STAGE, szText);
		pBerry->bHoursPerStage = (BYTE)(min(_tcstoul(szText, 0, 0), 0xFF));

		// ��
		GetDlgItemText(IDC_BERRY_SPICY, szText);
		pBerry->bSpicy = (BYTE)(min(_tcstoul(szText, 0, 0), 0xFF));

		// ɬ
		GetDlgItemText(IDC_BERRY_DRY, szText);
		pBerry->bDry = (BYTE)(min(_tcstoul(szText, 0, 0), 0xFF));

		// ��
		GetDlgItemText(IDC_BERRY_SWEET, szText);
		pBerry->bSweet = (BYTE)(min(_tcstoul(szText, 0, 0), 0xFF));

		// ��
		GetDlgItemText(IDC_BERRY_BITTER, szText);
		pBerry->bBitter = (BYTE)(min(_tcstoul(szText, 0, 0), 0xFF));

		// ��
		GetDlgItemText(IDC_BERRY_SOUR, szText);
		pBerry->bSour = (BYTE)(min(_tcstoul(szText, 0, 0), 0xFF));

		// ��
		GetDlgItemText(IDC_BERRY_FEEL, szText);
		pBerry->bFeel = (BYTE)(min(_tcstoul(szText, 0, 0), 0xFF));

		SetBerryListItem(m_dwCurSel);
	}
}

void CBerryDlg::OnHdnItemclickBerryBerryList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMHEADER phdr = reinterpret_cast<LPNMHEADER>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	static BerrySortParam bsp = { 0, TRUE };
	POSITION	pos;

	if(!rom.m_bOpened ||
		phdr->iItem == 1 ||	// ����
		phdr->iItem == 13)	// ˵��
	{
		return;
	}

	if(bsp.iSubItem == phdr->iItem)
	{
		bsp.bAscending = bsp.bAscending ? FALSE : TRUE;
	}
	else
	{
		bsp.iSubItem = phdr->iItem;
		bsp.bAscending = TRUE;
	}

	m_ctrlBerryList.SortItems(SortBerries, reinterpret_cast<LPARAM>(&bsp));

	pos = m_ctrlBerryList.GetFirstSelectedItemPosition();
	if(pos)
	{
		m_dwCurSel = m_ctrlBerryList.GetNextSelectedItem(pos);
		m_dwCurBerry = (DWORD)(m_ctrlBerryList.GetItemData(m_dwCurSel));
		m_ctrlBerryList.EnsureVisible(m_dwCurSel, FALSE);
	}
	else
	{
		m_dwCurSel = -1;
		m_dwCurBerry = -1;
	}
}

void CBerryDlg::OnLvnItemchangedBerryBerryList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	if((pNMLV->uNewState & (LVIS_SELECTED | LVIS_FOCUSED)) &&
		pNMLV->iItem != m_dwCurSel)
	{
		if(m_dwCurSel < BERRY_COUNT)
			GetBerry();

		m_dwCurSel = pNMLV->iItem;

		if(m_dwCurSel < BERRY_COUNT)
		{
			m_dwCurBerry = (DWORD)(m_ctrlBerryList.GetItemData(m_dwCurSel));
			SetBerry();
		}
		else
		{
			m_dwCurBerry = -1;
		}
	}
}
