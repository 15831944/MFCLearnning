
// 08_HuanDengPianDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMy08_HuanDengPianDlg �Ի���
class CMy08_HuanDengPianDlg : public CDialogEx
{
// ����
public:
	CMy08_HuanDengPianDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY08_HUANDENGPIAN_DIALOG };
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
	virtual void OnOK();
private:
	CStatic m_image;
	int m_w;
	int m_h;
public:
	afx_msg void OnBnClickedButton1();
private:
	bool m_isAuto;
	CButton m_preImg;
	CButton m_nextImg;
	CButton m_autoImg;
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
