#pragma once
#include "afxwin.h"
#include"UserSet.h"
#include"UserA.h"
// CUserAdd �Ի���

class CUserAdd : public CDialogEx
{
	DECLARE_DYNAMIC(CUserAdd)

public:
	CUserAdd(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CUserAdd();

	// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ADDUSER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CComboBox m_userType;
	CString m_uName;
	CString m_uAccount;
	CString m_uPwd;
	CUserSet m_userSet;


public:
	CList<CUserA>listUser;

	CString GetName() {
		return m_uName;
	}
	CString GetAccount() {
		return m_uAccount;
	}
	CString GetPwd() {
		return m_uPwd;
	}
	CString m_GetType;
	bool m_isAdd = false;

public:
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
	virtual BOOL OnInitDialog();
};
