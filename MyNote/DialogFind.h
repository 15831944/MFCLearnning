#pragma once

#define WM_FIND_EVENT  WM_USER + 106
// CDialogFind �Ի���
class CDialogFind : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogFind)

public:
	CDialogFind(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDialogFind();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_FIND };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
	virtual void OnCancel();
public:
	afx_msg void OnClose();

	BOOL SetIsOpen(BOOL & isOpen)
	{
		isOpen = 0;
		return isOpen;
	}
	BOOL m_isClose = FALSE;
private:
	int m_findIndex;
	bool m_isIgnoreCase;
public:
	bool m_isFindNext;
private:
	bool m_isLoop;
	virtual void PreInitDialog();
public:
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit1();
public:
	CString m_totalStr;
};
