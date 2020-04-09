// UserDelete.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "UserDelete.h"
#include "afxdialogex.h"



// CUserDelete �Ի���

IMPLEMENT_DYNAMIC(CUserDelete, CDialogEx)

CUserDelete::CUserDelete(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, m_userCount(_T(""))
{

}

CUserDelete::~CUserDelete()
{
}

void CUserDelete::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_userType);
	DDX_Text(pDX, IDC_EDIT1, m_userCount);
	DDX_Control(pDX, IDC_LIST1, m_listUser);
}


BEGIN_MESSAGE_MAP(CUserDelete, CDialogEx)
END_MESSAGE_MAP()


// CUserDelete ��Ϣ�������


void CUserDelete::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���

	//CDialogEx::OnOK();
}


BOOL CUserDelete::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_userType.InsertString(0, TEXT("����Ա"));
	m_userType.InsertString(1, TEXT("ҽ��"));
	m_userType.InsertString(2, TEXT("��ҩԱ"));
	m_userType.SetCurSel(0);

	CString type;
	m_userType.GetLBText(m_userType.GetCurSel(), type);

	m_listUser.SetExtendedStyle(m_listUser.GetExtendedStyle()
		|| LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

	CString head[] = {
		TEXT("�û����"),TEXT("�û��˺�"),TEXT("�û�����"),TEXT("�û�����")};

	int n = sizeof(head) / sizeof(head[0]);

	for (int i = 0; i < n; i++)
	{
		m_listUser.InsertColumn(i, head[i], LVCFMT_CENTER, 60);
	}
	/*CStringA	m_account;
	CStringA	m_password;
	CStringA	m_name;
	CStringA	m_classification;*/
	
	CString initSqlFilter;
	initSqlFilter.Format( TEXT("classification='%s'"), type);
	if (m_userSet.IsOpen() == FALSE) {
		m_userSet.Open();
	}
	m_userSet.m_strFilter = initSqlFilter;
	m_userSet.Requery();

	m_userSet.MoveFirst();

	int i = 0;
	while (!m_userSet.IsEOF()) {
		m_listUser.InsertItem(i, CString(m_userSet.m_classification));
		int j = 1;
		m_listUser.SetItemText(i,j++, CString(m_userSet.m_account));
		m_listUser.SetItemText(i, j++, CString(m_userSet.m_name));
		m_listUser.SetItemText(i, j++, CString(m_userSet.m_password));
		i++;
		m_userSet.MoveNext();
	}
	

	

	//CString filter = TEXT("classification='%s' and account='%s'", type, m_userCount);



	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
