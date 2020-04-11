#pragma once


// CPwdChange �Ի���
#include"UserSet.h"
#include "afxwin.h"
#include"blat32/blatdll.h"
#pragma  comment(lib,"blat")
class CPwdChange : public CDialogEx
{
	DECLARE_DYNAMIC(CPwdChange)

public:
	CPwdChange(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPwdChange();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CHAN_PWD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CString m_uName;
	CString m_uAccount;
	CString m_uPwd;
	CString m_newPwd;
	int m_uYzm;//���ɵ���֤��
	int m_yzm2;//�������֤��
	CUserSet m_userSet;

public:
	void SetName(CString uName) {
		this->m_uName = uName;
	}
	void SetAccount(CString uAccount) {
		this->m_uAccount = uAccount;
	}
	void SetPwd(CString uPwd) {
		this->m_uPwd = uPwd;
	}

	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton4();
private:
	CButton m_btnYzm;
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton5();
	
};
