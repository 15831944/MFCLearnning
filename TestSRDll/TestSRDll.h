
// TestSRDll.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTestSRDllApp: 
// �йش����ʵ�֣������ TestSRDll.cpp
//

class CTestSRDllApp : public CWinApp
{
public:
	CTestSRDllApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTestSRDllApp theApp;