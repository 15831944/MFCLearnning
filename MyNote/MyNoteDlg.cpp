
// MyNoteDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyNote.h"
#include "MyNoteDlg.h"
#include "afxdialogex.h"
#include<string>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyNoteDlg �Ի���



CMyNoteDlg::CMyNoteDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MYNOTE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyNoteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMyNoteDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_COMMAND(ID_32772, &CMyNoteDlg::OnOpenFile)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CMyNoteDlg ��Ϣ�������

BOOL CMyNoteDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMyNoteDlg::OnPaint()
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
HCURSOR CMyNoteDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMyNoteDlg::OnCancel()
{
	// TODO: �ڴ����ר�ô����/����û���

	//CDialogEx::OnCancel();
}


void CMyNoteDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���

	//CDialogEx::OnOK();
}

//���ڸı�ʱ�ı�ؼ���С
void CMyNoteDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	CRect rec;
	GetClientRect(&rec);
	
	CEdit *edit = (CEdit*)GetDlgItem(IDC_EDIT1);
	if(edit!=NULL)
	edit->MoveWindow(rec);


}


void CMyNoteDlg::OnOpenFile()
{
	// TODO: �ڴ���������������
	CFileDialog fDiaLog(TRUE, TEXT("*.txt"), _T("�½��ļ�"),
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		_T("txt Files (*.txt)|*.txt|cs Files (*.cs)|*.cs|Data Files (*.ini)|*.ini|All Files (*.*)|*.*||"),NULL);

	//CEdit *edit = (CEdit*)GetDlgItem(IDC_EDIT1);

	if (fDiaLog.DoModal() == IDOK) {
		CString pName = fDiaLog.GetPathName();

		CFile file;
		if (file.Open(pName, CFile::modeReadWrite, NULL)) {


			char *pBuf;
			char *copy;

			pBuf = new char[1024];
			int n = 0;
			CString  str;
			DWORD len = file.GetLength();
			int max = 0;
			while ((n=file.Read(pBuf,1024))>0) {
				max += n;
				


				copy = new  char[n+2];
				//strcpy_s(copy, n, pBuf);
				strncpy_s(copy,n+1, pBuf, n);
					//copy[n+1] = '/0';
				

				CString str1 = CA2W(pBuf, CP_UTF8); //Utf8��ʽ�ļ��ô˷���
				delete[] copy;
				str += str1;
				if (max >= len) {
					break;
				}
			}
			SetDlgItemText(IDC_EDIT1, str);
			file.Close();
		}
		else {
			MessageBox(_T("���ļ�ʧ�ܣ�"));
		}

	}

}


void CMyNoteDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	exit(1);
	CDialogEx::OnClose();
}
