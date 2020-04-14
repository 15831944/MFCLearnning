
// MainFrm.h : CMainFrame ��Ľӿ�
//

#pragma once
#include"stdafx.h"
#include <afxwin.h>
#include"Pic.h"
#include "ChildView.h"

class CMainFrame : public CFrameWnd
{
	
public:
	CMainFrame();
protected: 
	DECLARE_DYNAMIC(CMainFrame)

// ����
public:
	int bg_state, game_state, last_state;//�����л�2����Ϸ״̬,���gameover״̬

	int goals, best_goals;//����

	CRect m_client;
	CBitmap m_bgBitmap, m_tempBitmap;
	CDC m_cacheDC;   //����DC  
	CDC m_bgcDC, m_tempcDC;

	Pic pic;//����ͼƬ
// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);

// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	CChildView    m_wndView;

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSetFocus(CWnd *pOldWnd);
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
public:
	CBitmap bird[3][3];

};


