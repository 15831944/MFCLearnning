
// 12_FormView.h : 12_FormView Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy12_FormViewApp:
// �йش����ʵ�֣������ 12_FormView.cpp
//

class CMy12_FormViewApp : public CWinApp
{
public:
	CMy12_FormViewApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy12_FormViewApp theApp;
