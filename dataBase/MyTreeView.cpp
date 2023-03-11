// MyTreeView.cpp: файл реализации
//

#include "pch.h"
#include "dataBase.h"
#include "MyTreeView.h"
#include "dataBaseDoc.h"



// CMyTreeView

IMPLEMENT_DYNCREATE(CMyTreeView, CTreeView)

CMyTreeView::CMyTreeView()
{

}

CMyTreeView::~CMyTreeView()
{
}

BEGIN_MESSAGE_MAP(CMyTreeView, CTreeView)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()


// Диагностика CMyTreeView

#ifdef _DEBUG
void CMyTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


void CMyTreeView::FillTree()
{
	CTreeCtrl& tree = GetTreeCtrl();
	tree.DeleteAllItems();


	m_hAction = tree.InsertItem(L"Действия", -1, -1, NULL, TVI_FIRST);

	m_hAdd = tree.InsertItem(L"Добавить клиента", -1, -1, m_hAction, TVI_FIRST);
	m_hClientele = tree.InsertItem(L"Показать список всех клиентов", -1, -1, m_hAction, TVI_FIRST);
	m_hDelete = tree.InsertItem(L"Удалить клиента", -1, -1, m_hAction, TVI_FIRST);
	m_hFind = tree.InsertItem(L"Показать информацию о клиенте", -1, -1, m_hAction, TVI_FIRST);

	tree.Expand(m_hAction, TVE_EXPAND);
}



void CMyTreeView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	CTreeCtrl& tree = GetTreeCtrl();
	if (tree.GetSelectedItem() == m_hClientele)
	{
		m_pDoc->show_client();
	}
	else if (tree.GetSelectedItem() == m_hAdd)
	{
		m_pDoc->Add();
	}
	else if (tree.GetSelectedItem() == m_hDelete)
	{
		m_pDoc->Delete();
	}
	
	else if (tree.GetSelectedItem() == m_hFind)
	{
		m_pDoc->Find();
	}

	CTreeView::OnLButtonDblClk(nFlags, point);
}
