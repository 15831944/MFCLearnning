
// QQMsgBoom.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CQQMsgBoomApp: 
// �йش����ʵ�֣������ QQMsgBoom.cpp
//

class CQQMsgBoomApp : public CWinApp
{
public:
	CQQMsgBoomApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CQQMsgBoomApp theApp;