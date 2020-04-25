
// QQMsgBoomDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "QQMsgBoom.h"
#include "QQMsgBoomDlg.h"
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


// CQQMsgBoomDlg �Ի���



CQQMsgBoomDlg::CQQMsgBoomDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_QQMSGBOOM_DIALOG, pParent)
	, m_boom_filePath(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CQQMsgBoomDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CQQMsgBoomDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CQQMsgBoomDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CQQMsgBoomDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CQQMsgBoomDlg ��Ϣ�������

BOOL CQQMsgBoomDlg::OnInitDialog()
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

void CQQMsgBoomDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CQQMsgBoomDlg::OnPaint()
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
HCURSOR CQQMsgBoomDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//���ļ�
void CQQMsgBoomDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFileDialog fDiaLog(TRUE, TEXT("*.txt"), NULL,
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		_T("txt Files (*.txt)|*.txt|All Files (*.*)|*.*||"), NULL);

	if (fDiaLog.DoModal() == IDOK) {
		m_boom_filePath = fDiaLog.GetPathName();
		SetDlgItemText(IDC_BOOM_FILE, m_boom_filePath);
	}
}

void CQQMsgBoomDlg::OnBnClickedButton3()
{
	vector<CString> boomStr;
	boomStr.clear();
	boomStr.shrink_to_fit();

	CString qqNick;
	GetDlgItemText(IDC_QQ_NICK, qqNick);
	
	if (qqNick.IsEmpty()||m_boom_filePath.IsEmpty()) {
		AfxMessageBox(TEXT("qq�ǳƺ��ļ�·������Ϊ��"));
		return;
	}

	CString temp;
	GetDlgItemText(IDC_BOOM_TIMES, temp);//�õ���Ҫ���ú�ը�������ַ���

	int times = _ttoi(temp);
	if (times <= 0) {
		return;
	}

	CString tempCString;
	CStdioFile filein;//�����ļ���������
	if (filein.Open(m_boom_filePath, CFile::modeRead))//���ж�ȡboom�ļ�������
	{
		while (filein.ReadString(tempCString))
		{
			boomStr.push_back(tempCString);//����ѹ��m_BoomString������
		}
	}

	HWND hHandle = ::FindWindow(TEXT("TXGuiFoundation"), qqNick);//�ҵ���ǰQQ���ڵľ��
	if (!hHandle) {
		AfxMessageBox(L"δ�ҵ�����");
		return;
	}
	
	::ShowWindow(hHandle, 1);//��ʾ����
	::SetForegroundWindow(hHandle);//���õ��Ĵ������õ�ǰ̨�������
	
	for (int j = 0; j < times; ++j)
	{
		CString source;
		char * s = NULL;
		
		for (int i = 0; i < (int)boomStr.size(); ++i)
		{
			
			source = boomStr[i];
			if (s != NULL) {
				delete[] s;
				s = NULL;
			}

			int n = source.GetLength();
			
				//��ȡ���ֽ��ַ��Ĵ�С����С�ǰ��ֽڼ����
			 int len = WideCharToMultiByte(CP_ACP, 0, source, source.GetLength(), NULL, 0, NULL, NULL);
			
				 //Ϊ���ֽ��ַ���������ռ䣬�����СΪ���ֽڼ���Ŀ��ֽ��ֽڴ�С
				 s= new char[len + 1];   //���ֽ�Ϊ��λ
				 
				 WideCharToMultiByte(CP_ACP, 0, source, -1, s, len + 1, NULL, NULL);
				 
				 s[len] = '\0';
				
			if (OpenClipboard())//�򿪼��а�
			{
				
				 
				//TCHAR * buffer;//����ָ���ַ��͵�ָ�����
				char* buffer;
				//����һ��HGLOBAL�����������ָ�������ڴ��
				HGLOBAL clipbuffer = GlobalAlloc(GHND, len+1);
				//�ڶ��Ϸ�����ƶ����ڴ�飬���򷵻�һ���ڴ���
				
				buffer = (char*)GlobalLock(clipbuffer);  //�Է�����ڴ����м��������ڴ����ת����һ��ָ��,������Ӧ�����ü�������1
								
				strcpy_s(buffer,len+1, s);  //���û���������ݸ��Ƶ�ָ������У�ʵ���Ͼ��Ǹ��Ƶ�������ڴ����
				
				BOOL flag=GlobalUnlock(clipbuffer);//����д����ϣ����н����������������ü��������ּ�1
				
				EmptyClipboard();//��ռ����� 
				SetClipboardData(CF_TEXT, clipbuffer); //����������ݵ��ڴ�������������Դ������
				CloseClipboard();    //�رռ����壬�ͷż�������Դ��ռ��Ȩ
				
				::SendMessage(hHandle, WM_PASTE, 0, 0);//ģ��ճ������
				Sleep(1000);
				::SendMessage(hHandle, WM_KEYDOWN, VK_RETURN, 0);//ģ��س����������������ڵ���˷���				
			}
		}
	}
}
