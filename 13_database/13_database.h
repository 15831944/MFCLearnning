
// 13_database.h : 13_database Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy13_databaseApp:
// �йش����ʵ�֣������ 13_database.cpp
//

class CMy13_databaseApp : public CWinApp
{
public:
	CMy13_databaseApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy13_databaseApp theApp;
