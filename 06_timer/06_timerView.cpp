
// 06_timerView.cpp : CMy06_timerView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "06_timer.h"
#endif

#include "06_timerDoc.h"
#include "06_timerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy06_timerView

IMPLEMENT_DYNCREATE(CMy06_timerView, CView)

BEGIN_MESSAGE_MAP(CMy06_timerView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMy06_timerView ����/����

CMy06_timerView::CMy06_timerView()
{
	// TODO: �ڴ˴���ӹ������

}

CMy06_timerView::~CMy06_timerView()
{
}

BOOL CMy06_timerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy06_timerView ����

void CMy06_timerView::OnDraw(CDC* /*pDC*/)
{
	CMy06_timerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy06_timerView ��ӡ

BOOL CMy06_timerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy06_timerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy06_timerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy06_timerView ���

#ifdef _DEBUG
void CMy06_timerView::AssertValid() const
{
	CView::AssertValid();
}

void CMy06_timerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy06_timerDoc* CMy06_timerView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy06_timerDoc)));
	return (CMy06_timerDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy06_timerView ��Ϣ�������


int CMy06_timerView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������

	SetTimer(1, 500, NULL);

	return 0;
}


void CMy06_timerView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	static int w = 0;
	int imgW = 100, imgH = 100;
	if (nIDEvent == 1) {

		CClientDC dc(this);
		COLORREF  bkColor = dc.GetBkColor();
		CBrush *brush2 = new CBrush(bkColor);

		//��ÿͻ������
		CRect rec;
		GetClientRect(&rec);
		int wWith = rec.Width();

		int x = 10, y = 10;

		COLORREF color1 = RGB(255, 0, 0);
		COLORREF color2 = RGB(100, 0, 0);
		COLORREF color3 = RGB(200, 110, 0);
		COLORREF color4 = RGB(100, 100, 100);

		RectMove(dc, brush2, 10, 10, imgW, wWith, w1,color1);
		RectMove(dc, brush2, 40, 120, imgW, wWith, w2,color2);
		RectMove(dc, brush2, 70, 240, imgW, wWith, w3, color3);
		RectMove(dc, brush2, 100, 360, imgW, wWith, w4, color4);


	}


	CView::OnTimer(nIDEvent);
}

void CMy06_timerView::RectMove(CClientDC & dc, CBrush * brush2, int x, int y, int step,int wWith,int& w,COLORREF color)
{
	CBrush *brush = new CBrush(color);
	dc.SelectObject(brush);
	dc.Rectangle(x + w, y, x + step + w, y + imgH);


	dc.SelectObject(brush2);
	if (w != 0)
		dc.FillRect(new CRect(x + w - step, y, x + w, y + imgH), brush2);

	w += step;
	if (w > wWith) {
		dc.FillRect(new CRect(x + w - step, y, x + w, y + imgH), brush2);
		w = 0;
	}
}
