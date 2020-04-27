
// TestSRDllDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TestSRDll.h"
#include "TestSRDllDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestSRDllDlg �Ի���



CTestSRDllDlg::CTestSRDllDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TESTSRDLL_DIALOG, pParent)
	, m_path(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestSRDllDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestSRDllDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON1, &CTestSRDllDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CTestSRDllDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CTestSRDllDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CTestSRDllDlg ��Ϣ�������

BOOL CTestSRDllDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	if (m_tbl == NULL)
	{
		m_tbl = new Ctbl_dll();
		
	}
	if (m_tbl->IsOpen() == FALSE) {
		BOOL isOpen = m_tbl->Open(CRecordset::dynaset);
	}

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTestSRDllDlg::OnPaint()
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
HCURSOR CTestSRDllDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTestSRDllDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���

	//CDialogEx::OnOK();
}


void CTestSRDllDlg::OnCancel()
{
	// TODO: �ڴ����ר�ô����/����û���

	//CDialogEx::OnCancel();
}


void CTestSRDllDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//CDialogEx::OnClose();
	this->DestroyWindow();
	delete m_tbl;
	m_tbl = NULL;
}

//��
void CTestSRDllDlg::OnBnClickedButton1()
{
	CFileDialog fDiaLog(TRUE, TEXT("*.txt"),NULL,
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		_T("txt Files (*.dll)|*.dll|All Files (*.*)|*.*||"), NULL);
	CString path;
	if (fDiaLog.DoModal() == IDOK)
	{
		m_path = fDiaLog.GetPathName();
		SetDlgItemText(IDC_EDIT1, m_path);
	}
	else {
		return;
	}


}


void CTestSRDllDlg::OnBnClickedButton2()
{

	if (m_path.IsEmpty()) {
		return;
	}

	CFile file;
	CFileStatus filestatus;
	file.Open(m_path, CFile::modeRead);
	file.GetStatus(filestatus);
	m_tbl->AddNew();
	m_tbl->m_m_data.m_dwDataLength = filestatus.m_size;
	HGLOBAL hGlobal = GlobalAlloc(GPTR, filestatus.m_size);
	m_tbl->m_m_data.m_hData = GlobalLock(hGlobal);
	file.Read(m_tbl->m_m_data.m_hData, filestatus.m_size);	
	m_tbl->SetFieldDirty(&m_tbl->m_m_data);
	m_tbl->SetFieldNull(&m_tbl->m_m_data, FALSE);
	BOOL flag=m_tbl->Update();
	GlobalUnlock(hGlobal);
	if (flag == TRUE) {
		MessageBox(_T("����ɹ�"));
	}
	file.Close();
}


void CTestSRDllDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CFileDialog fDiaLog(FALSE, TEXT("*.dll"), TEXT("New.dll"),
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		_T("txt Files (*.dll)|*.dll|All Files (*.*)|*.*||"), NULL);
	CString path;
	if (fDiaLog.DoModal() == IDOK)
	{
		m_path = fDiaLog.GetPathName();
		SetDlgItemText(IDC_EDIT1, m_path);
	}
	else {
		return;
	}

	CFile file;
	CFileStatus filestatus;
	file.Open(m_path, CFile::modeCreate|CFile::modeWrite);

	m_tbl->MoveFirst();

	BYTE * byt = (BYTE*)GlobalLock(m_tbl->m_m_data.m_hData);

	file.Write(byt, m_tbl->m_m_data.m_dwDataLength);
	file.Close();
	GlobalUnlock(m_tbl->m_m_data.m_hData);
}
