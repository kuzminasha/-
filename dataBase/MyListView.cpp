// MyListView.cpp: файл реализации
//

#include "pch.h"
#include "dataBase.h"
#include "MyListView.h"


// CMyListView

IMPLEMENT_DYNCREATE(CMyListView, CListView)

CMyListView::CMyListView()
{

}

CMyListView::~CMyListView()
{
}

BEGIN_MESSAGE_MAP(CMyListView, CListView)
	ON_WM_CREATE()
END_MESSAGE_MAP()


// Диагностика CMyListView

#ifdef _DEBUG
void CMyListView::AssertValid() const
{
	CListView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyListView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif
#endif //_DEBUG


int CMyListView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	lpCreateStruct->style = LVS_REPORT;
	if (CListView::OnCreate(lpCreateStruct) == -1)
		return -1;
	CListCtrl& list = GetListCtrl();
	list.SetTextBkColor(RGB(247, 247, 193));
	list.DeleteAllItems();
	// TODO:  Добавьте специализированный код создания

	return 0;
}


void CMyListView::Fill_Client(CString id, CString FIO, int i)
{
	CListCtrl& list = GetListCtrl();
	RECT rcList;
	CWnd* pParentWnd = list.GetParent();

	ASSERT_VALID(pParentWnd);
	pParentWnd->ScreenToClient(&rcList);
	list.GetWindowRect(&rcList);

	if (i == -1)
	{
		list.InsertColumn(0, L"ID", LVCFMT_LEFT, 50);
		list.InsertColumn(1, L"ФИО", LVCFMT_LEFT, 350);
	}
	else
	{
		list.InsertItem(i, L"1");
		list.SetItemText(i, 0, id);
		list.SetItemText(i, 1, FIO);
	}
}

