#pragma once


// CUserLogin �Ի���
#include"UserSet.h"
#include "afxwin.h"
class CUserLogin : public CDialogEx
{
	DECLARE_DYNAMIC(CUserLogin)

public:
	CUserLogin(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CUserLogin();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

private:
	
	

	virtual void OnOK();
public:
	afx_msg void OnClose();

	// TODO: �ڴ����ר�ô����/����û���
	

	
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
private:
	CComboBox m_userClassify;
	CString m_uName;
	CString m_uPwd;
	CUserSet userSet;

public:
	CString GetLoginUserName() {
		return m_uName;
	}
};
