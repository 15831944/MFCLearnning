
// ListDirectoryFiles.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CListDirectoryFilesApp: 
// �йش����ʵ�֣������ ListDirectoryFiles.cpp
//

class CListDirectoryFilesApp : public CWinApp
{
public:
	CListDirectoryFilesApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CListDirectoryFilesApp theApp;