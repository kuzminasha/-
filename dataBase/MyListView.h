#pragma once
#include"afxcview.h."
#include"dataBaseDoc.h"

// Просмотр CMyListView

class CMyListView : public CListView
{
	DECLARE_DYNCREATE(CMyListView)

protected:
	CMyListView();           // защищенный конструктор, используемый при динамическом создании
	virtual ~CMyListView();

public:
	void Fill_Client(CString id, CString FIO, CString insurance, CString insurance_date, int i);


	CdataBaseDoc* m_pDoc;
	string sql;
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

	

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	void Delete_d();
};


