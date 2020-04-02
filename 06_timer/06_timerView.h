
// 06_timerView.h : CMy06_timerView ��Ľӿ�
//

#pragma once


class CMy06_timerView : public CView
{
protected: // �������л�����
	CMy06_timerView();
	DECLARE_DYNCREATE(CMy06_timerView)

// ����
public:
	CMy06_timerDoc* GetDocument() const;

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
	virtual ~CMy06_timerView();
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
	afx_msg void OnTimer(UINT_PTR nIDEvent);
private:
	int w1=0;
	int w2=0;
	int w3=0;
	int w4=0;
	int imgW=100;
	int imgH = 100;
	void RectMove(CClientDC& dc, CBrush *brush2, int x, int y, int step,int wWith,int& w, COLORREF color);
};

#ifndef _DEBUG  // 06_timerView.cpp �еĵ��԰汾
inline CMy06_timerDoc* CMy06_timerView::GetDocument() const
   { return reinterpret_cast<CMy06_timerDoc*>(m_pDocument); }
#endif

