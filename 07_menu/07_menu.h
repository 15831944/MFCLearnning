
// 07_menu.h : 07_menu Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy07_menuApp:
// �йش����ʵ�֣������ 07_menu.cpp
//

class CMy07_menuApp : public CWinAppEx
{
public:
	CMy07_menuApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy07_menuApp theApp;
