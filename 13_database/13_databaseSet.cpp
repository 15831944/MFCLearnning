
// 13_databaseSet.cpp : CMy13_databaseSet ���ʵ��
//

#include "stdafx.h"
#include "13_database.h"
#include "13_databaseSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy13_databaseSet ʵ��

// ���������� 2020��4��7��, 16:59

IMPLEMENT_DYNAMIC(CMy13_databaseSet, CRecordset)

CMy13_databaseSet::CMy13_databaseSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_id = 0;
	m_userName = L"";
	m_userAge = 0;
	m_userScore = 0.0;
	m_nFields = 4;
	m_nDefaultType = snapshot;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMy13_databaseSet::GetDefaultConnect()
{
	return _T("Description=MFC\x6d4b\x8bd5;DRIVER=SQL Server;SERVER=COMP-02-2433\\SQLEXPRESS;UID=sa;PWD=940619.lq;APP=Microsoft? Visual Studio? 2015;WSID=COMP-02-2433;DATABASE=Learnning;LANGUAGE=\x7b80\x4f53\x4e2d\x6587");
	//return _T("Description=MFC\x6d4b\x8bd5;DRIVER=SQL Server;SERVER=DESKTOP-I7LA8BS;UID=sa;PWD=940619.lq;APP=Microsoft? Visual Studio? 2015;WSID=COMP-02-2433;DATABASE=Learnning;LANGUAGE=\x7b80\x4f53\x4e2d\x6587");

}

CString CMy13_databaseSet::GetDefaultSQL()
{
	return _T("[dbo].[tbl_userScore]");
}

void CMy13_databaseSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_BigInt(pFX, _T("[id]"), m_id);
	RFX_Text(pFX, _T("[userName]"), m_userName);
	RFX_Long(pFX, _T("[userAge]"), m_userAge);
	RFX_Single(pFX, _T("[userScore]"), m_userScore);

}
/////////////////////////////////////////////////////////////////////////////
// CMy13_databaseSet ���

#ifdef _DEBUG
void CMy13_databaseSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMy13_databaseSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

