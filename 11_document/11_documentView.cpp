
// 11_documentView.cpp : CMy11_documentView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "11_document.h"
#endif

#include "11_documentDoc.h"
#include "11_documentView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy11_documentView

IMPLEMENT_DYNCREATE(CMy11_documentView, CView)

BEGIN_MESSAGE_MAP(CMy11_documentView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy11_documentView ����/����

CMy11_documentView::CMy11_documentView()
{
	// TODO: �ڴ˴���ӹ������

}

CMy11_documentView::~CMy11_documentView()
{
}

BOOL CMy11_documentView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy11_documentView ����

void CMy11_documentView::OnDraw(CDC* pDC)
{
	CMy11_documentDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	
	for (int i = 0; i < pDoc->m_num; i++)
	{
		CPoint pt = pDoc->m_point[i];

		pDC->Ellipse(pt.x - 5, pt.y - 5, pt.x + 5, pt.y + 5);
	}

}


// CMy11_documentView ��ӡ

BOOL CMy11_documentView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy11_documentView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy11_documentView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy11_documentView ���

#ifdef _DEBUG
void CMy11_documentView::AssertValid() const
{
	CView::AssertValid();
}

void CMy11_documentView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy11_documentDoc* CMy11_documentView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy11_documentDoc)));
	return (CMy11_documentDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy11_documentView ��Ϣ�������


void CMy11_documentView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CMy11_documentDoc* pDoc = GetDocument();

	if (pDoc->m_num > 199) {
		pDoc->m_num = 200;
		return;
	}

	pDoc->m_point[pDoc->m_num++] = point;

	Invalidate();

	CView::OnLButtonDown(nFlags, point);
}
