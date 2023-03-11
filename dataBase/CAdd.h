#pragma once
#include"dataBaseDoc.h"

// Диалоговое окно CAdd

class CAdd : public CDialog
{
	DECLARE_DYNAMIC(CAdd)


public:
	CAdd(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CAdd();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CdataBaseDoc* m_pDoc;
	CString FIO;
	CString insurance;
	CString year;
	CString month;
	CString day;
	afx_msg void OnEnChangeEdit6();
};
