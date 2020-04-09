// UserAdd.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "UserAdd.h"
#include "afxdialogex.h"



// CUserAdd �Ի���

IMPLEMENT_DYNAMIC(CUserAdd, CDialogEx)

CUserAdd::CUserAdd(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_ADDUSER, pParent)
	, m_uName(_T(""))
	, m_uAccount(_T(""))
	, m_uPwd(_T(""))
{

}

CUserAdd::~CUserAdd()
{
}

void CUserAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_userType);
	DDX_Text(pDX, IDC_EDIT1, m_uName);
	DDX_Text(pDX, IDC_EDIT3, m_uAccount);
	DDX_Text(pDX, IDC_EDIT2, m_uPwd);
}


BEGIN_MESSAGE_MAP(CUserAdd, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &CUserAdd::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CUserAdd::OnBnClickedButton2)
END_MESSAGE_MAP()


// CUserAdd ��Ϣ�������

//�˳�
void CUserAdd::OnBnClickedButton3()
{
	
	CDialogEx::OnCancel();
}

//����û�
void CUserAdd::OnBnClickedButton2()
{
	
	UpdateData(TRUE);

	if (m_uAccount.IsEmpty() || m_uName.IsEmpty() || m_uPwd.IsEmpty()) {
		MessageBox(_T("�ֶβ���Ϊ��"));
		return;
	}


	//TODO:��ӵ����ݿ���
	if (m_userSet.IsOpen() == FALSE) {
		m_userSet.Open(CRecordset::dynaset);
	}

	//�Ȳ����˺��Ƿ����
	CString sql;
	sql.Format(_T("account='%s'"), m_uAccount);

	m_userSet.m_strFilter = sql;

	m_userSet.Requery();

	if (m_userSet.GetRecordCount() >= 1) {
		MessageBox(TEXT("�˻��ظ��������"));
		m_uAccount = _T("");
		UpdateData(FALSE);
		return;
	}



	m_userSet.AddNew();
	m_userType.GetLBText(m_userType.GetCurSel(), m_GetType);
	
	m_userSet.m_classification = m_GetType;

	m_userSet.m_account = m_uAccount;
	m_userSet.m_name = m_uName;
	m_userSet.m_password = m_uPwd;

	m_userSet.Update();
	m_userSet.Requery();
	CUserA user;

	user.m_type = m_GetType;
	user.m_userName = m_uName;
	user.m_userPwd = m_uPwd;
	user.m_userAccount = m_uAccount;
	
	listUser.AddTail(user);

	m_uAccount = _T("");
	m_uName = _T("");
	m_uPwd = _T("");
	UpdateData(FALSE);

	m_isAdd = true;
	
	


	//CDialogEx::OnOK();

}


BOOL CUserAdd::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_userType.InsertString(0, TEXT("����Ա"));
	m_userType.InsertString(1, TEXT("ҽ��"));
	m_userType.InsertString(2, TEXT("��ҩԱ"));
	m_userType.SetCurSel(0);

	

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
