
// 09_���ܵİ�ť.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy09_���ܵİ�ťApp: 
// �йش����ʵ�֣������ 09_���ܵİ�ť.cpp
//

class CMy09_���ܵİ�ťApp : public CWinApp
{
public:
	CMy09_���ܵİ�ťApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy09_���ܵİ�ťApp theApp;