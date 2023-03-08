
// dataBase.h: основной файл заголовка для приложения dataBase
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CdataBaseApp:
// Сведения о реализации этого класса: dataBase.cpp
//

class CdataBaseApp : public CWinApp
{
public:
	CdataBaseApp() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CdataBaseApp theApp;
