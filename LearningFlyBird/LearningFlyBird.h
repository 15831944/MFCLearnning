
// LearningFlyBird.h : LearningFlyBird Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CLearningFlyBirdApp:
// �йش����ʵ�֣������ LearningFlyBird.cpp
//

class CLearningFlyBirdApp : public CWinApp
{
public:
	CLearningFlyBirdApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CLearningFlyBirdApp theApp;
