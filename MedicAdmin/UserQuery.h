#pragma once


// CUserQuery �Ի���

class CUserQuery : public CDialogEx
{
	DECLARE_DYNAMIC(CUserQuery)

public:
	CUserQuery(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CUserQuery();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_USER_QUERY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CString m_qCondtion;
public:
	afx_msg void OnBnClickedButton1();
	CString GetCondition() {
		return m_qCondtion;
	}
};
