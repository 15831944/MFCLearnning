
// 11_documentView.h : CMy11_documentView ��Ľӿ�
//

#pragma once


class CMy11_documentView : public CView
{
protected: // �������л�����
	CMy11_documentView();
	DECLARE_DYNCREATE(CMy11_documentView)

// ����
public:
	CMy11_documentDoc* GetDocument() const;

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
	virtual ~CMy11_documentView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 11_documentView.cpp �еĵ��԰汾
inline CMy11_documentDoc* CMy11_documentView::GetDocument() const
   { return reinterpret_cast<CMy11_documentDoc*>(m_pDocument); }
#endif

