
// ForTreeCtrlDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"


// CForTreeCtrlDlg �Ի���
class CForTreeCtrlDlg : public CDialogEx
{
// ����
public:
	CForTreeCtrlDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORTREECTRL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	void CForTreeCtrlDlg::func(HTREEITEM root, CString find);
	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CTreeCtrl treeCtrl;
	CString m_find;
public:
	afx_msg void OnBnClickedButton1();
};
