
// 08_HuanDengPian.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy08_HuanDengPianApp: 
// �йش����ʵ�֣������ 08_HuanDengPian.cpp
//

class CMy08_HuanDengPianApp : public CWinApp
{
public:
	CMy08_HuanDengPianApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy08_HuanDengPianApp theApp;