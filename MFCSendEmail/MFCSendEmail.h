
// MFCSendEmail.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCSendEmailApp: 
// �йش����ʵ�֣������ MFCSendEmail.cpp
//

class CMFCSendEmailApp : public CWinApp
{
public:
	CMFCSendEmailApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCSendEmailApp theApp;