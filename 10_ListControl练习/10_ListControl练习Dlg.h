
// 10_ListControl��ϰDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMy10_ListControl��ϰDlg �Ի���
class CMy10_ListControl��ϰDlg : public CDialogEx
{
// ����
public:
	CMy10_ListControl��ϰDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY10_LISTCONTROL_DIALOG };
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
	// ��
//	CButton m_rcMan;
	CString m_check;
public:
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
private:
	CComboBox m_people;
	int m_age;
};
