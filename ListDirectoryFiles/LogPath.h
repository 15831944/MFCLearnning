#pragma once
#include "afxwin.h"
#define WM_SENDPATH WM_USER+134

// CLogPath �Ի���

class CLogPath : public CDialogEx
{
	DECLARE_DYNAMIC(CLogPath)

public:
	CLogPath(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLogPath();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOG_PATH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_listBox;
	afx_msg void OnLbnSelchangeList1();
};
