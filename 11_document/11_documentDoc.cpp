
// 11_documentDoc.cpp : CMy11_documentDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "11_document.h"
#endif

#include "11_documentDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy11_documentDoc

IMPLEMENT_DYNCREATE(CMy11_documentDoc, CDocument)

BEGIN_MESSAGE_MAP(CMy11_documentDoc, CDocument)
END_MESSAGE_MAP()


// CMy11_documentDoc ����/����

CMy11_documentDoc::CMy11_documentDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CMy11_documentDoc::~CMy11_documentDoc()
{
}

BOOL CMy11_documentDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CMy11_documentDoc ���л�

void CMy11_documentDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
		ar << m_num;

		for (int i = 0; i < m_num; i++)
		{
			ar << m_point[i];
		}
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
		ar >> m_num;
		for (int i = 0; i < m_num; i++)
		{
			ar >> m_point[i];
		}
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CMy11_documentDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CMy11_documentDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CMy11_documentDoc::SetSearchContent(const CString& value)
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

// CMy11_documentDoc ���

#ifdef _DEBUG
void CMy11_documentDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy11_documentDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy11_documentDoc ����


void CMy11_documentDoc::DeleteContents()
{
	// TODO: �ڴ����ר�ô����/����û���

	m_num = 0;

	memset(&m_point, 0, sizeof(m_point));

	CDocument::DeleteContents();
}
