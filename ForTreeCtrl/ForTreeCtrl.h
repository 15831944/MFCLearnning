
// ForTreeCtrl.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CForTreeCtrlApp: 
// �йش����ʵ�֣������ ForTreeCtrl.cpp
//

class CForTreeCtrlApp : public CWinApp
{
public:
	CForTreeCtrlApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CForTreeCtrlApp theApp;