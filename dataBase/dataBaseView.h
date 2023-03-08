
// dataBaseView.h: интерфейс класса CdataBaseView
//

#pragma once
#include "dataBaseDoc.h"

//class CdataBaseDoc;

class CdataBaseView : public CView
{
protected: // создать только из сериализации
	CdataBaseView() noexcept;
	DECLARE_DYNCREATE(CdataBaseView)

// Атрибуты
public:
	CdataBaseDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CdataBaseView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // версия отладки в dataBaseView.cpp
inline CdataBaseDoc* CdataBaseView::GetDocument() const
   { return reinterpret_cast<CdataBaseDoc*>(m_pDocument); }
#endif

