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
END_MESSAGE_MAP()


// CLogPath ��Ϣ�������
