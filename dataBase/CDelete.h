#pragma once
#include "dataBaseDoc.h"

// Диалоговое окно CDelete

class CDelete : public CDialog
{
	DECLARE_DYNAMIC(CDelete)

public:
	CDelete(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CDelete();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DELETE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CString FIO;
	CdataBaseDoc* m_pDoc;
};
