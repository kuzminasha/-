#pragma once
#include"afxcview.h."

// Просмотр CMyTreeView

class CdataBaseDoc;

class CMyTreeView : public CTreeView
{
	DECLARE_DYNCREATE(CMyTreeView)

protected:
	CMyTreeView();           // защищенный конструктор, используемый при динамическом создании
	virtual ~CMyTreeView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

	CdataBaseDoc* m_pDoc;
	HTREEITEM m_hFind, m_hAdd, m_hClientele, m_hDelete, m_hAction;
	void FillTree();


protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};


