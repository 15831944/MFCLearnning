
// 10_ListControl��ϰDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "10_ListControl��ϰ.h"
#include "10_ListControl��ϰDlg.h"
#include "afxdialogex.h"
#include"People.h"
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


// CMy10_ListControl��ϰDlg �Ի���



CMy10_ListControl��ϰDlg::CMy10_ListControl��ϰDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY10_LISTCONTROL_DIALOG, pParent)
	, m_check(_T(""))
	, m_age(0)

{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy10_ListControl��ϰDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_BUTTON1, m_rcMan);
	DDX_Control(pDX, IDC_COMBO1, m_people);
	DDX_Control(pDX, IDC_LIST1, m_list);
	//  DDX_Control(pDX, IDC_EDIT1, m_age);
	//  DDX_Text(pDX, IDC_EDIT1, m_age);
	DDX_Text(pDX, IDC_EDIT1, m_age);
}

BEGIN_MESSAGE_MAP(CMy10_ListControl��ϰDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO1, &CMy10_ListControl��ϰDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMy10_ListControl��ϰDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy10_ListControl��ϰDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy10_ListControl��ϰDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMy10_ListControl��ϰDlg ��Ϣ�������

BOOL CMy10_ListControl��ϰDlg::OnInitDialog()
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

	CheckRadioButton(IDC_RADIO1, IDC_RADIO2, IDC_RADIO1);

	CString people[10] = { TEXT("��һ"),TEXT("���"), TEXT("����"), TEXT("Ǯ��"), TEXT("���"),
		TEXT("����"), TEXT("����"), TEXT("����"), TEXT("����"), TEXT("������") };

	for (int i = 0; i < 10; i++)
	{
		m_people.InsertString(i, people[i]);

	}
	m_people.SetCurSel(0);

	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

	m_list.InsertColumn(0, TEXT("����"),LVCFMT_LEFT,50);
	m_list.InsertColumn(1, TEXT("�Ա�"),LVCFMT_LEFT,50); 
	m_list.InsertColumn(2, TEXT("����"),LVCFMT_LEFT,50);

	m_check = TEXT("��");
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMy10_ListControl��ϰDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy10_ListControl��ϰDlg::OnPaint()
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
HCURSOR CMy10_ListControl��ϰDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy10_ListControl��ϰDlg::OnBnClickedRadio1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_check = TEXT("��");
}


void CMy10_ListControl��ϰDlg::OnBnClickedRadio2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_check = TEXT("Ů");
}


void CMy10_ListControl��ϰDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	static int i = 0;

	CString strName;

	m_people.GetLBText(m_people.GetCurSel(), strName);
	m_list.InsertItem(i, strName);
	int j = 1;
	m_list.SetItemText(i, j++, m_check);
	CString strNum;
	strNum.Format(TEXT("%d"), m_age);
	m_list.SetItemText(i++, j, strNum);
}


void CMy10_ListControl��ϰDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

		if (m_list.GetSelectedCount() > 0) {

		POSITION pos=	m_list.GetFirstSelectedItemPosition();

		while (pos)
		{
			int nSelected = m_list.GetNextSelectedItem(pos); //��ȡѡ���е�����
			m_list.DeleteItem(nSelected); //��������ɾ��
			pos = m_list.GetFirstSelectedItemPosition();
		}

		}

}
