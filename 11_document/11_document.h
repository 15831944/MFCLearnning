
// 11_document.h : 11_document Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy11_documentApp:
// �йش����ʵ�֣������ 11_document.cpp
//

class CMy11_documentApp : public CWinAppEx
{
public:
	CMy11_documentApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy11_documentApp theApp;
