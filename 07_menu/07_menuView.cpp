
// 07_menuView.cpp : CMy07_menuView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "07_menu.h"
#endif

#include "07_menuDoc.h"
#include "07_menuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy07_menuView

IMPLEMENT_DYNCREATE(CMy07_menuView, CView)

BEGIN_MESSAGE_MAP(CMy07_menuView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy07_menuView ����/����

CMy07_menuView::CMy07_menuView()
{
	// TODO: �ڴ˴���ӹ������

}

CMy07_menuView::~CMy07_menuView()
{
}

BOOL CMy07_menuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy07_menuView ����

void CMy07_menuView::OnDraw(CDC* /*pDC*/)
{
	CMy07_menuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy07_menuView ��ӡ

BOOL CMy07_menuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy07_menuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy07_menuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy07_menuView ���

#ifdef _DEBUG
void CMy07_menuView::AssertValid() const
{
	CView::AssertValid();
}

void CMy07_menuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy07_menuDoc* CMy07_menuView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy07_menuDoc)));
	return (CMy07_menuDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy07_menuView ��Ϣ�������


int CMy07_menuView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������

	return 0;
}


void CMy07_menuView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ


	//���ﲻ����getMenu()��Ϊ������õĲ˵�������Frame�ģ������ǲ�������������View�ϣ�
	//����Ҫ��View�ϼ���һ���˵���


	CMenu menu;

	menu.LoadMenuW(IDR_MAINFRAME);

	CMenu *subMenu = menu.GetSubMenu(0);

	ClientToScreen(&point);

	subMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON,
		point.x, point.y, this);

	CView::OnLButtonDown(nFlags, point);
}
