// UserLogin.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "UserLogin.h"
#include "afxdialogex.h"


// CUserLogin �Ի���

IMPLEMENT_DYNAMIC(CUserLogin, CDialogEx)

CUserLogin::CUserLogin(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_uName(_T(""))
	, m_uPwd(_T(""))
{

}

CUserLogin::~CUserLogin()
{
}

void CUserLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_userClassify);
	DDX_Text(pDX, IDC_EDIT1, m_uName);
	DDX_Text(pDX, IDC_EDIT2, m_uPwd);
}


BEGIN_MESSAGE_MAP(CUserLogin, CDialogEx)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON2, &CUserLogin::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CUserLogin::OnBnClickedButton1)
END_MESSAGE_MAP()


// CUserLogin ��Ϣ�������


void CUserLogin::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���

	//CDialogEx::OnOK();
}


void CUserLogin::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	exit(1);
	CDialogEx::OnClose();
}


void CUserLogin::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(1);
}
BOOL CUserLogin::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	m_userClassify.InsertString(0, TEXT("����Ա"));
	m_userClassify.InsertString(1, TEXT("ҽ��"));
	m_userClassify.InsertString(2, TEXT("��ҩԱ"));
	m_userClassify.SetCurSel(1);

	m_uName = TEXT("�����");
	m_uPwd = TEXT("123456");
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}

void CUserLogin::OnBnClickedButton1()
{
	UpdateData(true);

	CString filter;

	CString type;
	m_userClassify.GetLBText(m_userClassify.GetCurSel(), type);

	filter.Format(TEXT("name='%s' and password='%s' and classification='%s'"), m_uName, m_uPwd, type);
	
	if (userSet.IsOpen() == FALSE) {
		userSet.Open();
	}
	userSet.m_strFilter = filter;

	userSet.Requery();

	if (userSet.GetRecordCount() == 1) {
		CDialogEx::OnOK();
	}
	else {
		MessageBox(TEXT("��¼ʧ��"));
		m_uName = TEXT("");
		m_uPwd = TEXT("");
		UpdateData(FALSE);
	}

}



