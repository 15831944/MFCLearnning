
// ForTreeCtrlDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ForTreeCtrl.h"
#include "ForTreeCtrlDlg.h"
#include "afxdialogex.h"
#include<vector>
using namespace std;

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


// CForTreeCtrlDlg �Ի���



CForTreeCtrlDlg::CForTreeCtrlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FORTREECTRL_DIALOG, pParent)
	, m_find(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CForTreeCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, treeCtrl);
	DDX_Text(pDX, IDC_EDIT1, m_find);
}

BEGIN_MESSAGE_MAP(CForTreeCtrlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CForTreeCtrlDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CForTreeCtrlDlg ��Ϣ�������

BOOL CForTreeCtrlDlg::OnInitDialog()
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
	CString root[2] = { TEXT("A"),TEXT("B") };

	for (int i=0;i<2;i++)
	{
		HTREEITEM r =treeCtrl.InsertItem(root[i], NULL);

		CString str;
		for (int j=0;j<3;j++)
		{
			str.Format(TEXT("%s%d"),root[i], j + 1);
			HTREEITEM j1 = treeCtrl.InsertItem(str, r);

			CString str1;
			for (int m = 0; m < 3; m++) {

				str1.Format(TEXT("%s%d%d"),  root[i], j + 1,m+1);
				HTREEITEM m1 = treeCtrl.InsertItem(str1, j1);

				CString str2;
				for (int q = 0; q < 3; q++) {

					str2.Format(TEXT("%s%d%d%d"), root[i], j + 1, m + 1,q+1);
					HTREEITEM q1 = treeCtrl.InsertItem(str2, m1);

					CString str3;
					for (int s = 0; s < 3; s++) {

						str3.Format(TEXT("%s%d%d%d%d"), root[i], j + 1, m + 1, q + 1,s+1);
						HTREEITEM s1 = treeCtrl.InsertItem(str3, q1);

					}

				}

			}
		}

	}

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CForTreeCtrlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CForTreeCtrlDlg::OnPaint()
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
HCURSOR CForTreeCtrlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CForTreeCtrlDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	UpdateData(TRUE);

	vector<HTREEITEM>vecItem;
	HTREEITEM root = treeCtrl.GetRootItem();
	//��һ����ڵ�
	while (root != NULL) {

		vecItem.push_back(root);
		root = treeCtrl.GetNextItem(root, TVGN_NEXT);
	}
	for (int q = (int)vecItem.size() - 1; q > -1; q--) {
		func(vecItem[q], m_find);
	}

}
void CForTreeCtrlDlg::func(HTREEITEM root,CString condition) {
	
	CString itemText = treeCtrl.GetItemText(root);

	if (itemText.Find(condition) != -1) {

		treeCtrl.SelectItem(root);
		treeCtrl.SetCheck(root, TRUE);
		treeCtrl.Expand(root, TVM_EXPAND);
		
		return;

	}
	//���ڵ�Ķ��ӽڵ�
	HTREEITEM A1 = treeCtrl.GetChildItem(root);

	//���ӽڵ���ֵܽڵ�
	vector<HTREEITEM>vecItem;

	while (A1 != NULL) {

		vecItem.push_back(A1);
		A1 = treeCtrl.GetNextItem(A1, TVGN_NEXT);
	}

	for (int q = (int)vecItem.size() - 1; q > -1; q--) {

		CString itemText = treeCtrl.GetItemText(vecItem[q]);

		if (itemText.Find(condition) != -1) {

			treeCtrl.SelectItem(vecItem[q]);
			treeCtrl.SetCheck(vecItem[q], TRUE);
			treeCtrl.Expand(vecItem[q], TVM_EXPAND);
			vecItem.clear();
			return;

		}
		else {
			//�ݹ飬���ӽڵ㵱�����ڵ����
			func(vecItem[q], condition);
		}

	}


}
