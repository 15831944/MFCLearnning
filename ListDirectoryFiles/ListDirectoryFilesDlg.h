
// ListDirectoryFilesDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include"LogPath.h"
#include<vector>
#include<iterator>
using namespace std;
// CListDirectoryFilesDlg �Ի���
class CListDirectoryFilesDlg : public CDialogEx
{
// ����
public:
	CListDirectoryFilesDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LISTDIRECTORYFILES_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg
		void ListFiles(CString path);
	void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
	virtual void OnCancel();
public:
	afx_msg void OnClose();
private:
	CListCtrl m_list;
public:
	afx_msg void OnBnClickedSearch();
private:
	CString m_dirPath;
	CButton m_btnBack;
	CButton m_btnFward;
	CButton m_btnDown;
	CButton m_btnUp;
	CLogPath *m_logPh=NULL;
	vector<CString>vecPath;
public:
//	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
private:
	CListBox m_logPath;
	BOOL m_logIsShow;
public:
	afx_msg void OnBnClickedBtnDown();
private:
	
public:
	afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
private:
	CString m_chanPath;
};
