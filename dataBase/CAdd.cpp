// CAdd.cpp: файл реализации
//

#include "pch.h"
#include "dataBase.h"
#include "CAdd.h"
#include "afxdialogex.h"


// Диалоговое окно CAdd

IMPLEMENT_DYNAMIC(CAdd, CDialog)

CAdd::CAdd(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_ADD, pParent)
	, FIO(_T(""))
	, insurance(_T(""))
	, year(_T(""))
	, month(_T(""))
	, day(_T(""))
{

}

CAdd::~CAdd()
{
}

void CAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, FIO);
	DDV_MaxChars(pDX, FIO, 100);
	DDX_Text(pDX, IDC_EDIT3, year);
	DDV_MaxChars(pDX, year, 4);
	DDX_Text(pDX, IDC_EDIT4, month);
	DDV_MaxChars(pDX, month, 2);
	DDX_Text(pDX, IDC_EDIT5, day);
	DDV_MaxChars(pDX, day, 2);
	DDX_Text(pDX, IDC_EDIT6, insurance);
	DDV_MaxChars(pDX, insurance, 50);
}


BEGIN_MESSAGE_MAP(CAdd, CDialog)
	
END_MESSAGE_MAP()


// Обработчики сообщений CAdd




