// CFind.cpp: файл реализации
//

#include "pch.h"
#include "dataBase.h"
#include "CFind.h"
#include "afxdialogex.h"


// Диалоговое окно CFind

IMPLEMENT_DYNAMIC(CFind, CDialog)

CFind::CFind(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_FIND, pParent), FIO(_T(""))
{

}

CFind::~CFind()
{
}

void CFind::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, FIO);
}


BEGIN_MESSAGE_MAP(CFind, CDialog)
	ON_BN_CLICKED(IDOK, &CFind::OnBnClickedOk)
END_MESSAGE_MAP()


// Обработчики сообщений CFind





void CFind::OnBnClickedOk()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialog::OnOK();
}
