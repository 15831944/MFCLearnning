// PwdChange.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "PwdChange.h"
#include "afxdialogex.h"


// CPwdChange �Ի���

IMPLEMENT_DYNAMIC(CPwdChange, CDialogEx)

CPwdChange::CPwdChange(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_CHAN_PWD, pParent)
	, m_uName(_T(""))
	, m_uAccount(_T(""))
	, m_uPwd(_T(""))
	, m_newPwd(_T(""))
	, m_uYzm(0)
	, m_yzm2(0)
{

}

CPwdChange::~CPwdChange()
{
}

void CPwdChange::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_uName);
	DDX_Text(pDX, IDC_EDIT2, m_uAccount);
	DDX_Text(pDX, IDC_EDIT3, m_uPwd);
	DDX_Text(pDX, IDC_EDIT4, m_newPwd);
	//  DDX_Text(pDX, IDC_EDIT6, m_uYzm);
	DDX_Control(pDX, IDC_BUTTON4, m_btnYzm);
	DDX_Text(pDX, IDC_EDIT6, m_yzm2);
}


BEGIN_MESSAGE_MAP(CPwdChange, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON4, &CPwdChange::OnBnClickedButton4)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON5, &CPwdChange::OnBnClickedButton5)
END_MESSAGE_MAP()


// CPwdChange ��Ϣ�������


BOOL CPwdChange::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	UpdateData(FALSE);
	
	//�򿪵�ʱ�������֤��
	//ÿ���������ɵ����������һ���ģ����������
	m_uYzm =123456+ rand()%10000;

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CPwdChange::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//������֤��
	typedef int(__stdcall*pSend)(LPCSTR sCmd);
	HINSTANCE hdll;
	pSend mySend;
	hdll = LoadLibrary(TEXT("blat32/blat.dll"));
	mySend = (pSend)GetProcAddress(hdll, "Send");
	//int x = mySend(cmd);

	CString yzm;
	yzm.Format(TEXT("��֤��:%d"),m_uYzm);

	CString cmd2;// = TEXT("-to kwjf11@sina.com -subject �������� -body '%s' -u 576484879@qq.com -pw lakqyyyykfnrbehi -charset utf-8");
	cmd2.Format(TEXT("-to kwjf11@sina.com -subject �������� -body %s -u 576484879@qq.com -pw lakqyyyykfnrbehi -charset utf-8"), yzm);
	wchar_t *sBuf = cmd2.AllocSysString();
	DWORD dBufSize = WideCharToMultiByte(CP_OEMCP, 0, sBuf, -1, NULL, 0, NULL, FALSE);

	//����Ŀ�껺��
	char *dBuf = new char[dBufSize];
	memset(dBuf, 0, dBufSize);

	//ת��
	int nRet = WideCharToMultiByte(CP_OEMCP, 0, sBuf, -1, dBuf, dBufSize, NULL, FALSE);


	int x = mySend(dBuf);

	m_btnYzm.EnableWindow(FALSE);

	SetTimer(1, 1000, NULL);

}


void CPwdChange::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	static int i = 60;

	if (nIDEvent == 1) {

		if (i-- >=1) {
			CString str;
			str.Format(TEXT("ʣ�ࣺ%ds"), i);

			m_btnYzm.SetWindowTextW(str);

		}
		else {

			i = 60;
			
			CString str= TEXT("��ȡ��֤��");
			m_btnYzm.EnableWindow(TRUE);
			m_btnYzm.SetWindowTextW(str);

			KillTimer(1);

			m_uYzm = 654321 + rand() % 10000;

		}

	}


	CDialogEx::OnTimer(nIDEvent);
}


void CPwdChange::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m_yzm2 < 10000 || m_yzm2 != m_uYzm) {
		MessageBox(_T("��֤�����벻��ȷ������60������д����"));
		return;
	}
	else {
		//TODO: ��������
		//MessageBox(_T("��������"));
		if (m_userSet.IsOpen() == FALSE) {
			m_userSet.Open(CRecordset::dynaset);
		}

		CString filter;
		filter.Format(TEXT("account='%s'"), m_uAccount);
		m_userSet.m_strFilter = filter;
		m_userSet.Requery();

		m_userSet.Edit();

		m_userSet.m_password = m_newPwd;

		m_userSet.Update();
		MessageBox(TEXT("�޸ĳɹ�"));

		CDialogEx::OnOK();
	}
}
