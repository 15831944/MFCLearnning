
// MFC_��ݼ�.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFC_��ݼ�App: 
// �йش����ʵ�֣������ MFC_��ݼ�.cpp
//

class CMFC_��ݼ�App : public CWinApp
{
public:
	CMFC_��ݼ�App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC_��ݼ�App theApp;