// UserQuery.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "UserQuery.h"
#include "afxdialogex.h"


// CUserQuery �Ի���

IMPLEMENT_DYNAMIC(CUserQuery, CDialogEx)

CUserQuery::CUserQuery(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_USER_QUERY, pParent)
	, m_qCondtion(_T(""))
{

}

CUserQuery::~CUserQuery()
{
}

void CUserQuery::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_qCondtion);
}


BEGIN_MESSAGE_MAP(CUserQuery, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CUserQuery::OnBnClickedButton1)
END_MESSAGE_MAP()


// CUserQuery ��Ϣ�������

//��ѯ
void CUserQuery::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CDialogEx::OnOK();
}
