
// 13_databaseView.h : CMy13_databaseView ��Ľӿ�
//

#pragma once


class CMy13_databaseView : public CFormView
{
protected: // �������л�����
	CMy13_databaseView();
	DECLARE_DYNCREATE(CMy13_databaseView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY13_DATABASE_FORM };
#endif

// ����
public:
	CMy13_databaseDoc* GetDocument() const;

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
	virtual ~CMy13_databaseView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
private:
	int m_uiId;
	CString m_uiName;
	int m_uiAge;
	float m_uiScore;
public:
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // 13_databaseView.cpp �еĵ��԰汾
inline CMy13_databaseDoc* CMy13_databaseView::GetDocument() const
   { return reinterpret_cast<CMy13_databaseDoc*>(m_pDocument); }
#endif

