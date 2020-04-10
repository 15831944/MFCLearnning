
// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "MedicAdmin.h"

#include "MainFrm.h"
#include"UserLogin.h"
#include"UserDelete.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
CString G_LoginName = TEXT("");
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_32776, &CMainFrame::On32776)
	ON_COMMAND(ID_32774, &CMainFrame::On32774)
	ON_COMMAND(ID_32778, &CMainFrame::OnExit)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	SetMenu(NULL);

	CMenu menu;
	menu.LoadMenuW(IDR_MENU1);
	
	SetMenu(&menu);
	menu.Detach();
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	

	



	return TRUE;
}

// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame ��Ϣ�������



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: �ڴ����ר�ô����/����û���
	CUserLogin userLogin;
	userLogin.DoModal();
	G_LoginName = userLogin.GetLoginUserName();


	m_sWnd.CreateStatic(this,1,2, WS_CHILD | WS_VISIBLE, AFX_IDW_PANE_FIRST);
	m_sWnd.CreateView(0, 0, RUNTIME_CLASS(CUserTreeView), CSize(230, 600), pContext);
	m_sWnd.CreateView(0, 1, RUNTIME_CLASS(CMedicListView), CSize(720, 600), pContext);


	return TRUE;
	//return CFrameWnd::OnCreateClient(lpcs, pContext);
}


void CMainFrame::On32776()
{
	// TODO: �ڴ���������������
	CUserDelete deleteDialog;

	deleteDialog.DoModal();
}

//�����û�
void CMainFrame::On32774()
{
	// TODO: �ڴ���������������
	//��������
	wchar_t pBuf[MAX_PATH];
	//��ȡӦ�ó�����ȫ·������ GetCurrentDirectory ���ö���
	GetModuleFileName(NULL, pBuf, MAX_PATH);

	STARTUPINFO startupinfo;
	PROCESS_INFORMATION proc_info;
	memset(&startupinfo, 0, sizeof(STARTUPINFO));
	startupinfo.cb = sizeof(STARTUPINFO);
	// ����Ҫ�ĵط�
	::CreateProcess(pBuf, NULL, NULL, NULL, FALSE,
		NORMAL_PRIORITY_CLASS, NULL, NULL, &startupinfo, &proc_info);

	PostMessage(WM_QUIT);
}

//�˳�ϵͳ
void CMainFrame::OnExit()
{
	// TODO: �ڴ���������������
	PostMessage(WM_QUIT);
}
