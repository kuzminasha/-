
// dataBaseView.cpp: реализация класса CdataBaseView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "dataBase.h"
#include <stdlib.h>
#endif

#include "dataBaseDoc.h"
#include "dataBaseView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CdataBaseView

IMPLEMENT_DYNCREATE(CdataBaseView, CView)

BEGIN_MESSAGE_MAP(CdataBaseView, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// Создание или уничтожение CdataBaseView

CdataBaseView::CdataBaseView() noexcept
{
	// TODO: добавьте код создания

}

CdataBaseView::~CdataBaseView()
{
}

BOOL CdataBaseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Рисование CdataBaseView

void CdataBaseView::OnDraw(CDC* /*pDC*/)
{
	CdataBaseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки для собственных данных
}


// Печать CdataBaseView

BOOL CdataBaseView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CdataBaseView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CdataBaseView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// Диагностика CdataBaseView

#ifdef _DEBUG
void CdataBaseView::AssertValid() const
{
	CView::AssertValid();
}

void CdataBaseView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CdataBaseDoc* CdataBaseView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CdataBaseDoc)));
	return (CdataBaseDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CdataBaseView


void CdataBaseView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	SetTimer(0, 1, NULL);
}


void CdataBaseView::OnTimer(UINT_PTR nIDEvent)
{
	Invalidate();

	CView::OnTimer(nIDEvent);
}
