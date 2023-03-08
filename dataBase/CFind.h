#pragma once


// Диалоговое окно CFind

class CFind : public CDialog
{
	DECLARE_DYNAMIC(CFind)

public:
	CFind(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CFind();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FIND };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
};
