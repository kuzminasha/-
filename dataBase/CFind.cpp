// CFind.cpp: файл реализации
//

#include "pch.h"
#include "dataBase.h"
#include "CFind.h"
#include "afxdialogex.h"


// Диалоговое окно CFind

IMPLEMENT_DYNAMIC(CFind, CDialog)

CFind::CFind(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_FIND, pParent)
{

}

CFind::~CFind()
{
}

void CFind::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFind, CDialog)
END_MESSAGE_MAP()


// Обработчики сообщений CFind
