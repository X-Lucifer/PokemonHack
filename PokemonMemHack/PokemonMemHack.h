// PokemonMemHack.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error �ڰ������� PCH �Ĵ��ļ�֮ǰ������stdafx.h��
#endif

/////////////////////////////////////////////////
//#define BREED_COUNT	(0x19C)	// (412)
//#define SKILL_COUNT	(0x163)	// (355)
#define AREA_COUNT	(0x100)	// (256)
#define ITEM_COUNT	(0x179)	// (375)
#define PS_COUNT	(25)
//#define SPEC_COUNT	(0x4E)	// (78)
#define SPEC_COUNT	(0x8F)	// (143)

/////////////////////////////////////////////////
#include "resource.h"		// ������
#include "StringReader.h"
#include "SkillListBox.h"
#include "SkillComboBox.h"
#include "PokemonMemHackCore.h"
#include "PokemonMemHackDlg.h"

#define GUI_FONT_NAME	"MS Gothic"
#define GUI_FONT_HEIGHT	12

enum { ui_count_none=0, ui_count_dec=1, ui_count_hex=2 };

struct ConfigStruct
{
	DWORD			dwLang;
	DWORD			dwCount;
	StringEntry *	pBreedNameList;
	StringEntry *	pSkillNameList;
	StringEntry *	pSkillDescList;
	StringEntry *	pAreaNameList;
	StringEntry *	pItemNameList;
	StringEntry *	pItemDescList;
	StringEntry *	pPsNameList;		// persionality list
	StringEntry *	pSpecNameList;		// specialty
	StringEntry *	pSpecDescList;
};

// CPokemonMemHackApp:
// �йش����ʵ�֣������ PokemonMemHack.cpp
//

class CPokemonMemHackApp : public CWinApp
{
public:
	CPokemonMemHackApp();
	~CPokemonMemHackApp();

// ��д
public:
	virtual BOOL InitInstance();

	BOOL ReadStringLists();
	VOID DestroyStringLists();
	VOID ReadINI();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CPokemonMemHackApp theApp;
extern ConfigStruct	cfg;
extern CPokemonMemHackCore g_MemHack;
extern CPokemonRom g_MemRom;

extern COLORREF	g_rgBackClrTable[];
extern COLORREF	g_rgForeClrTable[];
extern DWORD	g_dwBackClrCount;
extern DWORD	g_dwForeClrCount;
extern DWORD	g_dwExtraBreeds;