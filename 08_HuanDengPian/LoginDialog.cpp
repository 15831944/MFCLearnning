// LoginDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "08_HuanDengPian.h"
#include "LoginDialog.h"
#include "afxdialogex.h"


// CLoginDialog �Ի���

IMPLEMENT_DYNAMIC(CLoginDialog, CDialogEx)

CLoginDialog::CLoginDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_LOGIN, pParent)
	, m_userName(_T(""))
	, m_pwd(_T(""))
{

}

CLoginDialog::~CLoginDialog()
{
}

void CLoginDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_userName);
	DDX_Text(pDX, IDC_EDIT2, m_pwd);
}


BEGIN_MESSAGE_MAP(CLoginDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &CLoginDialog::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CLoginDialog::OnBnClickedButton1)
	ON_WM_CLOSE()
//	ON_WM_CHAR()
END_MESSAGE_MAP()


// CLoginDialog ��Ϣ�������


void CLoginDialog::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(1);
}

//��¼��ť
void CLoginDialog::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);

	if (m_userName ==TEXT("L")&&m_pwd == TEXT("L")) {
		CDialogEx::OnOK();

	}
	else {

		MessageBox(TEXT("�û������������"));

	}
}


void CLoginDialog::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���

	//CDialogEx::OnOK();
}


void CLoginDialog::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	exit(1);
}


//void CLoginDialog::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//
//	if (nChar == VK_RETURN) {
//
//		OnBnClickedButton1();
//	}
//
//
//	CDialogEx::OnChar(nChar, nRepCnt, nFlags);
//}


BOOL CLoginDialog::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���

	if (pMsg->message == WM_KEYDOWN) {

		if (pMsg->wParam == VK_RETURN)
		{
			OnBnClickedButton1();
		}
	}


	return CDialogEx::PreTranslateMessage(pMsg);
}
