
// 13_databaseSet.cpp : CMy13_databaseSet 类的实现
//

#include "stdafx.h"
#include "13_database.h"
#include "13_databaseSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy13_databaseSet 实现

// 代码生成在 2020年4月7日, 16:59

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
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
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
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_BigInt(pFX, _T("[id]"), m_id);
	RFX_Text(pFX, _T("[userName]"), m_userName);
	RFX_Long(pFX, _T("[userAge]"), m_userAge);
	RFX_Single(pFX, _T("[userScore]"), m_userScore);

}
/////////////////////////////////////////////////////////////////////////////
// CMy13_databaseSet 诊断

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

