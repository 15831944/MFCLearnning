
// 13_databaseDoc.h : CMy13_databaseDoc ��Ľӿ�
//


#pragma once
#include"13_databaseSet.h"

class CMy13_databaseDoc : public CDocument
{
protected: // �������л�����
	CMy13_databaseDoc();
	DECLARE_DYNCREATE(CMy13_databaseDoc)

// ����
public:

// ����
public:
	CMy13_databaseSet *GetSet() {
		return &pSet;
	}

private:
	CMy13_databaseSet pSet;

// ��д
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMy13_databaseDoc();
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
};
