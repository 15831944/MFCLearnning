// UserSet.h : CUserSet ���ʵ��



// CUserSet ʵ��

// ���������� 2020��4��8��, 15:20

#include "stdafx.h"
#include "UserSet.h"
IMPLEMENT_DYNAMIC(CUserSet, CRecordset)

CUserSet::CUserSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_account = "";
	m_password = "";
	m_name = "";
	m_classification = "";
	m_nFields = 4;
	m_nDefaultType = snapshot;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CUserSet::GetDefaultConnect()
{
	return _T("Description=MEdicODBC;DRIVER=SQL Server;SERVER=COMP-02-2433\\SQLEXPRESS;UID=sa;PWD=940619.lq;APP=Microsoft? Visual Studio? 2015;WSID=COMP-02-2433;DATABASE=medicine");
	//  return _T("Description=MEdicODBC;DRIVER=SQL Server;SERVER=DESKTOP-I7LA8BS;UID=sa;PWD=940619.lq;APP=Microsoft? Visual Studio? 2015;WSID=COMP-02-2433;DATABASE=medicine");

}

CString CUserSet::GetDefaultSQL()
{
	return _T("[dbo].[user]");
}

void CUserSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[account]"), m_account);
	RFX_Text(pFX, _T("[password]"), m_password);
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Text(pFX, _T("[classification]"), m_classification);

}
/////////////////////////////////////////////////////////////////////////////
// CUserSet ���

#ifdef _DEBUG
void CUserSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CUserSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


