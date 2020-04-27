// tbl_dll.h : Ctbl_dll ���ʵ��



// Ctbl_dll ʵ��

// ���������� 2020��4��27��, 20:25

#include "stdafx.h"
#include "tbl_dll.h"
IMPLEMENT_DYNAMIC(Ctbl_dll, CRecordset)

Ctbl_dll::Ctbl_dll(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_id = 0;
	m_m_data;
	m_nFields = 2;
	m_nDefaultType = snapshot;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString Ctbl_dll::GetDefaultConnect()
{
	return _T("Description=\x6d4b\x8bd5\x8bfb\x53d6\x4e8c\x8fdb\x5236;DRIVER=SQL Server;SERVER=DESKTOP-I7LA8BS;UID=sa;PWD=940619.lq;APP=Microsoft? Visual Studio? 2015;WSID=DESKTOP-I7LA8BS;DATABASE=Learnning");
}

CString Ctbl_dll::GetDefaultSQL()
{
	return _T("[dbo].[tbl_dll]");
}

void Ctbl_dll::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_BigInt(pFX, _T("[id]"), m_id);
	RFX_LongBinary(pFX, _T("[m_data]"), m_m_data);

}
/////////////////////////////////////////////////////////////////////////////
// Ctbl_dll ���

#ifdef _DEBUG
void Ctbl_dll::AssertValid() const
{
	CRecordset::AssertValid();
}

void Ctbl_dll::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


