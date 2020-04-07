
// 12_FormViewDoc.cpp : CMy12_FormViewDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "12_FormView.h"
#endif

#include "12_FormViewDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy12_FormViewDoc

IMPLEMENT_DYNCREATE(CMy12_FormViewDoc, CDocument)

BEGIN_MESSAGE_MAP(CMy12_FormViewDoc, CDocument)
END_MESSAGE_MAP()


// CMy12_FormViewDoc ����/����

CMy12_FormViewDoc::CMy12_FormViewDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CMy12_FormViewDoc::~CMy12_FormViewDoc()
{
}

BOOL CMy12_FormViewDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CMy12_FormViewDoc ���л�

void CMy12_FormViewDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CMy12_FormViewDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CMy12_FormViewDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CMy12_FormViewDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMy12_FormViewDoc ���

#ifdef _DEBUG
void CMy12_FormViewDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy12_FormViewDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy12_FormViewDoc ����


void CMy12_FormViewDoc::DeleteContents()
{
	// TODO: �ڴ����ר�ô����/����û���
	/*while (m_list.GetHeadPosition() != NULL) {

		CStudent stu = m_list.RemoveHead();

	}
	m_pos = NULL;*/
	m_list.RemoveAll();
	m_pos = NULL;


	CDocument::DeleteContents();
}
