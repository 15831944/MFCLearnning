
// TestSRDllDlg.h : ͷ�ļ�
//

#pragma once
#define FLAG 0
#include"tbl_dll.h"
#include"MyTestDLL.h"
#include"Interface.h"
# if FLAG
#include"MyTestDLL.h"
#pragma  comment(lib,"MyTestDLL")
#endif
// CTestSRDllDlg �Ի���
class CTestSRDllDlg : public CDialogEx
{
// ����
public:
	CTestSRDllDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTSRDLL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
	virtual void OnCancel();
public:
	afx_msg void OnClose();

private:
	Ctbl_dll *m_tbl;
public:
	afx_msg void OnBnClickedButton1();
private:
	CString m_path;
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
};
