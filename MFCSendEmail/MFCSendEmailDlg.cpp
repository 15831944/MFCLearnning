
// MFCSendEmailDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCSendEmail.h"
#include "MFCSendEmailDlg.h"
#include "afxdialogex.h"
#include"blat32/blatdll.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//extern __declspec(dllimport) int APIENTRY Send(LPCTSTR sCmd);
#pragma  comment(lib,"blat")
// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCSendEmailDlg �Ի���



CMFCSendEmailDlg::CMFCSendEmailDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCSENDEMAIL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCSendEmailDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCSendEmailDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCSendEmailDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMFCSendEmailDlg ��Ϣ�������

BOOL CMFCSendEmailDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCSendEmailDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCSendEmailDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCSendEmailDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCSendEmailDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	//CString cmd = TEXT("-install smtp.qq.com 576484879@qq.com");
	
	typedef int(__stdcall*pSend)(LPCSTR sCmd);
	HINSTANCE hdll;
	pSend mySend;
	hdll = LoadLibrary(TEXT("blat32/blat.dll"));
	mySend = (pSend)GetProcAddress(hdll, "Send");
	//int x = mySend(cmd);
	
	CString yzm = TEXT("��֤�룺6666ddd");

	CString cmd2;// = TEXT("-to kwjf11@sina.com -subject �������� -body '%s' -u 576484879@qq.com -pw lakqyyyykfnrbehi -charset utf-8");
	cmd2.Format(TEXT("-to kwjf11@sina.com -subject �������� -body '%s' -u 576484879@qq.com -pw lakqyyyykfnrbehi -charset utf-8"),yzm);
	wchar_t *sBuf = cmd2.AllocSysString();
	DWORD dBufSize = WideCharToMultiByte(CP_OEMCP, 0, sBuf, -1, NULL, 0, NULL, FALSE);

	//����Ŀ�껺��
	char *dBuf = new char[dBufSize];
	memset(dBuf, 0, dBufSize);

	//ת��
	int nRet = WideCharToMultiByte(CP_OEMCP, 0, sBuf, -1, dBuf, dBufSize, NULL, FALSE);

	
	int x = mySend(dBuf);

	delete dBuf;
	dBuf = NULL;

	//Send(cmd);
	//-to kwjf11@sina.com - subject �������� - body ��֤�룺6666 - sig LLLLL - ps psps
}
