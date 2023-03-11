// CDELETE.cpp: файл реализации
//

#include "pch.h"
#include "dataBase.h"
#include "CDelete.h"
#include "afxdialogex.h"


// Диалоговое окно CDELETE

IMPLEMENT_DYNAMIC(CDelete, CDialog)

CDelete::CDelete(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DELETE, pParent), FIO(_T(""))
{

}

CDelete::~CDelete()
{
}

void CDelete::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, FIO);
}


BEGIN_MESSAGE_MAP(CDelete, CDialog)
END_MESSAGE_MAP()


// Обработчики сообщений CDELETE
