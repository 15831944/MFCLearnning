#pragma once
#include<afxwin.h>

class MyApp :public CWinApp {

public :

	virtual BOOL InitInstance();

};

class MyFrame :public CFrameWnd {

public:

	MyFrame();
	// ��Ա����
	DECLARE_MESSAGE_MAP()
	afx_msg void OnLButtonDown(UINT, CPoint);
	afx_msg void OnPaint();

};

