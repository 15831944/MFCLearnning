
// 07_menuView.h : CMy07_menuView ��Ľӿ�
//

#pragma once


class CMy07_menuView : public CView
{
protected: // �������л�����
	CMy07_menuView();
	DECLARE_DYNCREATE(CMy07_menuView)

// ����
public:
	CMy07_menuDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMy07_menuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 07_menuView.cpp �еĵ��԰汾
inline CMy07_menuDoc* CMy07_menuView::GetDocument() const
   { return reinterpret_cast<CMy07_menuDoc*>(m_pDocument); }
#endif

