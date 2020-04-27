// LogPath.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ListDirectoryFiles.h"
#include "LogPath.h"
#include "afxdialogex.h"


// CLogPath �Ի���

IMPLEMENT_DYNAMIC(CLogPath, CDialogEx)

CLogPath::CLogPath(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LOG_PATH, pParent)
{

}

CLogPath::~CLogPath()
{
}

void CLogPath::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listBox);
}


BEGIN_MESSAGE_MAP(CLogPath, CDialogEx)
	ON_LBN_SELCHANGE(IDC_LIST1, &CLogPath::OnLbnSelchangeList1)
END_MESSAGE_MAP()


// CLogPath ��Ϣ�������


void CLogPath::OnLbnSelchangeList1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HWND hWnd = AfxGetApp()->GetMainWnd()->GetSafeHwnd();
	int index = m_listBox.GetCurSel();

	::SendMessage(hWnd, WM_SENDPATH, 0, index);
}
