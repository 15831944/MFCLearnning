
// 09_���ܵİ�ťDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "MyButton.h"


// CMy09_���ܵİ�ťDlg �Ի���
class CMy09_���ܵİ�ťDlg : public CDialogEx
{
// ����
public:
	CMy09_���ܵİ�ťDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY09__DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CButton m_btn;
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
private:
	MyButton m_myBtn;
	int m_w;
	int m_h;
};
