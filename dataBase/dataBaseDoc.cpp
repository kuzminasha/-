
// dataBaseDoc.cpp: реализация класса CdataBaseDoc 
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "dataBase.h"
#endif

#include "dataBaseDoc.h"
#include "MyTreeView.h"
#include "dataBaseView.h"
#include "MainFrm.h";
#include "MyListView.h"

#include <propkey.h>
#include "CFind.h"
#include "CDelete.h"
#include "CAdd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CdataBaseDoc

IMPLEMENT_DYNCREATE(CdataBaseDoc, CDocument)

BEGIN_MESSAGE_MAP(CdataBaseDoc, CDocument)
END_MESSAGE_MAP()


// Создание или уничтожение CdataBaseDoc

CdataBaseDoc::CdataBaseDoc() noexcept
{
	// TODO: добавьте код для одноразового вызова конструктора

}

CdataBaseDoc::~CdataBaseDoc()
{
}

BOOL CdataBaseDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	conn = mysql_init(NULL);

	mysql_set_character_set(conn, "cp1251");
	conn = mysql_real_connect(conn, "127.0.0.1", "root", "Ufdhbr_2008.", "coursework", NULL, NULL, 0);

	if (!conn)
	{
		MessageBox(NULL, L"Failed to connect to database", L"INFO", MB_OK);
		return 0;
	}

	CWnd* MainWnd = AfxGetMainWnd();

	if (MainWnd)
	{
		m_pTreeView = (CMyTreeView*)((CMainFrame*)MainWnd)->m_wndSplitter.GetPane(0, 0);
		m_pView = (CMyListView*)((CMainFrame*)MainWnd)->m_wndSplitter.GetPane(0, 1);
		m_pTreeView->m_pDoc = this;
	}
	m_pTreeView->FillTree();

	return TRUE;
}




// Сериализация CdataBaseDoc

void CdataBaseDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: добавьте код сохранения
	}
	else
	{
		// TODO: добавьте код загрузки
	}
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void CdataBaseDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Поддержка обработчиков поиска
void CdataBaseDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задание содержимого поиска из данных документа.
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void CdataBaseDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Диагностика CdataBaseDoc

#ifdef _DEBUG
void CdataBaseDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CdataBaseDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Команды CdataBaseDoc

void CdataBaseDoc::show_client()
{
	CMyListView* m_list = (CMyListView*)m_pView;
	m_list->Delete_d();
	string sql = "select * from clientele;";
	CString str1, str2, str3, str4;
	mysql_query(conn, sql.c_str());
	if (reslogon = mysql_store_result(conn))
	{
		int i = -1;
		while (row = mysql_fetch_row(reslogon))
		{
			m_list->Fill_Client(str1, str2, str3, str4, i);
			str1 = row[0];
			str2 = row[1];
			str3 = row[2];
			str4 = row[3];
			i++;
		}
		m_list->Fill_Client(str1, str2, str3, str4, i);
	}
	mysql_free_result(reslogon);
}
void CdataBaseDoc::Find()
{

	CFind dlg;
	if (dlg.DoModal() != IDOK)
		return;

	FIO = dlg.FIO;
	CT2CA pszConvertedAnsiString(FIO);
	string fio(pszConvertedAnsiString);

	CMyListView* m_list = (CMyListView*)m_pView;
	m_list->Delete_d();     
	string sql = "SELECT * FROM clientele WHERE clientname like '" + fio +"%' ;";
	CString str1, str2, str3, str4;
	mysql_query(conn, sql.c_str());
	if (reslogon = mysql_store_result(conn))
	{
		int i = -1;
		while (row = mysql_fetch_row(reslogon))
		{
			m_list->Fill_Client(str1, str2, str3, str4, i);
			str1 = row[0];
			str2 = row[1];
			str3 = row[2];
			str4 = row[3];
			i++;
		}
		m_list->Fill_Client(str1, str2, str3, str4, i);
	}
	mysql_free_result(reslogon);
}
void CdataBaseDoc::Delete()
{
	CDelete dlg;
	if (dlg.DoModal() != IDOK)
		return;

	FIO = dlg.FIO;
	CT2CA pszConvertedAnsiString(FIO);
	string fio(pszConvertedAnsiString);

	CMyListView* m_list = (CMyListView*)m_pView;
	m_list->Delete_d(); 
	string sql = "DELETE FROM clientele WHERE clientname like '" + fio + "%' ;";

	mysql_query(conn, sql.c_str());
	int result = mysql_query(conn, sql.c_str());
	if (!result)
	{
		AfxMessageBox(L"Удаление успешно!");
	}
	else
	{
		AfxMessageBox(L"Возникли проблемы, попробуйте еще раз");
	}

}
void CdataBaseDoc::Add()
{
	CAdd dlg;
	if (dlg.DoModal() != IDOK)
		return;

	FIO = dlg.FIO;
	insurance = dlg.insurance;
	insurance_date = dlg.year + '-' + dlg.month + '-' + dlg.day;



	CT2CA pszConvertedAnsiString(FIO);
	string FIO1(pszConvertedAnsiString);

	CT2CA pszConvertedAnsiString1(insurance);
	string insurance1(pszConvertedAnsiString1);

	CT2CA pszConvertedAnsiString2(insurance_date);
	string insurance_date1(pszConvertedAnsiString2);


	string sql = "INSERT INTO clientele VALUES(NULL, '"+FIO1+"', '"+insurance1+"', '"+insurance_date1+"');";
	int result = mysql_query(conn, sql.c_str());
	if (!result)
	{
		AfxMessageBox(L"Клиент успешно добавлен!");
	}
	else
	{
		AfxMessageBox(L"Возникли проблемы, попробуйте еще раз!");
	}
}