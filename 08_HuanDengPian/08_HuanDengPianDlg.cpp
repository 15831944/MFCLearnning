
// 08_HuanDengPianDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "08_HuanDengPian.h"
#include "08_HuanDengPianDlg.h"
#include "afxdialogex.h"
#include"resource.h"
#define HBMP(filepath,width,height) (HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CMy08_HuanDengPianDlg �Ի���



CMy08_HuanDengPianDlg::CMy08_HuanDengPianDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY08_HUANDENGPIAN_DIALOG, pParent)
	, m_w(0)
	, m_h(0)
	, m_isAuto(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy08_HuanDengPianDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BMP, m_image);
	DDX_Control(pDX, IDC_BUTTON2, m_preImg);
	DDX_Control(pDX, IDC_BUTTON3, m_nextImg);
	DDX_Control(pDX, IDC_BUTTON1, m_autoImg);
}

BEGIN_MESSAGE_MAP(CMy08_HuanDengPianDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMy08_HuanDengPianDlg::OnBnClickedButton1)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CMy08_HuanDengPianDlg ��Ϣ�������

BOOL CMy08_HuanDengPianDlg::OnInitDialog()
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

	m_image.ModifyStyle(0xf,SS_BITMAP | SS_CENTERIMAGE);

	CRect rect;
	
	m_image.GetWindowRect(&rect);

	m_w = rect.Width();
	m_h = rect.Height();

	m_image.SetBitmap(HBMP(TEXT("../image/1.bmp"), m_w, m_h));

	m_isAuto = false;

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMy08_HuanDengPianDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy08_HuanDengPianDlg::OnPaint()
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
HCURSOR CMy08_HuanDengPianDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy08_HuanDengPianDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���

	CDialogEx::OnOK();
}


void CMy08_HuanDengPianDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_isAuto = !m_isAuto;

	if (m_isAuto) {

		SetTimer(1, 1200, NULL);

		
		m_preImg.EnableWindow(FALSE);
		m_nextImg.EnableWindow(FALSE);
	}
	else {
		
		m_preImg.EnableWindow(TRUE);
		m_nextImg.EnableWindow(TRUE);
		KillTimer(1);
	}

}


void CMy08_HuanDengPianDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	static int i = 1;

	if (nIDEvent == 1) {

		i++;

		if (i > 24) {
			i = 1;
		}
		CString str;
		str.Format(TEXT("../image/%d.bmp"), i);

			m_image.SetBitmap(HBMP(str, m_w, m_h));
	}


	CDialogEx::OnTimer(nIDEvent);
}
