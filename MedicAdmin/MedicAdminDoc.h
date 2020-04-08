
// MedicAdminDoc.h : CMedicAdminDoc ��Ľӿ�
//


#pragma once
#include"MedicSet.h"
#include"UserSet.h"

class CMedicAdminDoc : public CDocument
{
protected: // �������л�����
	CMedicAdminDoc();
	DECLARE_DYNCREATE(CMedicAdminDoc)

// ����
public:
	CMedicSet * GetMedicSet() {
		return &m_pMySet;
	}
	CUserSet *GetUserSet() {
		return &m_pUserSet;
	}

// ����
private:
	CMedicSet m_pMySet;
	CUserSet m_pUserSet;

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
	virtual ~CMedicAdminDoc();
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
