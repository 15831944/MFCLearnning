
// 06_timer.h : 06_timer Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy06_timerApp:
// �йش����ʵ�֣������ 06_timer.cpp
//

class CMy06_timerApp : public CWinAppEx
{
public:
	CMy06_timerApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy06_timerApp theApp;
