
// 10_ListControl��ϰ.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy10_ListControl��ϰApp: 
// �йش����ʵ�֣������ 10_ListControl��ϰ.cpp
//

class CMy10_ListControl��ϰApp : public CWinApp
{
public:
	CMy10_ListControl��ϰApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy10_ListControl��ϰApp theApp;