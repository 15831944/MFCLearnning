
// 12_FormViewView.h : CMy12_FormViewView ��Ľӿ�
//

#pragma once
#include "afxwin.h"


class CMy12_FormViewView : public CFormView
{
protected: // �������л�����
	CMy12_FormViewView();
	DECLARE_DYNCREATE(CMy12_FormViewView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY12_FORMVIEW_FORM };
#endif

// ����
public:
	CMy12_FormViewDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CMy12_FormViewView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
private:
	CButton m_buttonPre;
	CButton m_buttonNext;
	CString m_xuehao;
	CString m_xm;
	int m_age;
	double m_cj;
public:
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedRadio1();
private:
	CButton m_buttonAdd;
public:
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};

#ifndef _DEBUG  // 12_FormViewView.cpp �еĵ��԰汾
inline CMy12_FormViewDoc* CMy12_FormViewView::GetDocument() const
   { return reinterpret_cast<CMy12_FormViewDoc*>(m_pDocument); }
#endif

