
// 13_databaseView.cpp : CMy13_databaseView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "13_database.h"
#endif

#include "13_databaseDoc.h"
#include "13_databaseView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy13_databaseView

IMPLEMENT_DYNCREATE(CMy13_databaseView, CFormView)

BEGIN_MESSAGE_MAP(CMy13_databaseView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy13_databaseView::OnBnClickedButton1)
END_MESSAGE_MAP()

// CMy13_databaseView ����/����

CMy13_databaseView::CMy13_databaseView()
	: CFormView(IDD_MY13_DATABASE_FORM)
	, m_uiId(0)
	, m_uiName(_T(""))
	, m_uiAge(0)
	, m_uiScore(0)
{
	// TODO: �ڴ˴���ӹ������

}

CMy13_databaseView::~CMy13_databaseView()
{
}

void CMy13_databaseView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_uiId);
	DDX_Text(pDX, IDC_EDIT1, m_uiName);
	DDX_Text(pDX, IDC_EDIT3, m_uiAge);
	DDX_Text(pDX, IDC_EDIT4, m_uiScore);
}

BOOL CMy13_databaseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CFormView::PreCreateWindow(cs);
}

void CMy13_databaseView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CMy13_databaseView ���

#ifdef _DEBUG
void CMy13_databaseView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMy13_databaseView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMy13_databaseDoc* CMy13_databaseView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy13_databaseDoc)));
	return (CMy13_databaseDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy13_databaseView ��Ϣ�������

//��һ��
void CMy13_databaseView::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
