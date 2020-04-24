
// MyNoteDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include"DialogFind.h"


// CMyNoteDlg �Ի���
class CMyNoteDlg : public CDialogEx
{
// ����
public:
	CMyNoteDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYNOTE_DIALOG };
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
	afx_msg LRESULT OnFindStr(WPARAM wParam, LPARAM iParam);
	DECLARE_MESSAGE_MAP()
	virtual void OnCancel();
	virtual void OnOK();
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnOpenFile();
	afx_msg void OnClose();
	afx_msg void OnNewFile();
private:
	CString m_fileName;
	CDialogFind m_diaFind;
public:
	afx_msg void OnSaveFile();
	afx_msg void OnDropFiles(HDROP hDropInfo);
	void ReadAnsi(CFile & file);
	void ReadUTF8(CFile & file);
	void ReadUnicode(CFile & file);
	afx_msg void OnSaveAs();
	afx_msg void OnFind();
	afx_msg void OnFont();
	void SetTitle();
private:
	CFont m_font;
public:
	afx_msg void OnInsertDate();
private:
	BOOL m_findOpen;
public:
	afx_msg void OnCopyOther();
};
