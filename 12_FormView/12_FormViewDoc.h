
// 12_FormViewDoc.h : CMy12_FormViewDoc ��Ľӿ�
//


#pragma once
#include"Student.h"

class CMy12_FormViewDoc : public CDocument
{
protected: // �������л�����
	CMy12_FormViewDoc();
	DECLARE_DYNCREATE(CMy12_FormViewDoc)

// ����
public:
	CList<CStudent> m_list;
	POSITION m_pos=NULL;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMy12_FormViewDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	virtual void DeleteContents();
};
