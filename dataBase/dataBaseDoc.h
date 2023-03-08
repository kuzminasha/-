
// dataBaseDoc.h: интерфейс класса CdataBaseDoc 
//


#pragma once
#include <string>
#include <mysql.h>

using namespace std;

class CMyTreeView;
class CMyListView;
class CdataBaseView;

class CdataBaseDoc : public CDocument
{
protected: // создать только из сериализации
	CdataBaseDoc() noexcept;
	DECLARE_DYNCREATE(CdataBaseDoc)

// Атрибуты
public:
	CMyTreeView* m_pTreeView;
	CMyListView* m_pListView;
	CView* m_pView;
	MYSQL* conn;
	MYSQL_RES* reslogon;
	MYSQL_ROW row;

	CString id, FIO;
	

// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CdataBaseDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void show_client();
};
