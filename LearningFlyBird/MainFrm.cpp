
// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "LearningFlyBird.h"
#include"Resource.h"

#include "MainFrm.h"
#define PI 3.1415926

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	for (int i = 0; i < 1; i++)
	{
		Pipe temp;
		pipes.AddHead(temp);
	}
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// ����һ����ͼ��ռ�ÿ�ܵĹ�����
	if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW,
		CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	{
		TRACE0("δ�ܴ�����ͼ����\n");
		return -1;
	}
	CRect rect(0, 0, 286, 512);       //����ͻ������ھ�����״
	CalcWindowRect(&rect);            //���ݷֱ��ʡ��˵�...���㴰�ھ��δ�С�������ڴ��ڴ�������ã�

	SetWindowPos(NULL, 0, 0, rect.Width(), rect.Height(),
		SWP_NOZORDER | SWP_NOMOVE | SWP_NOREDRAW);

	CDC *cDC = this->GetDC();
	GetClientRect(&m_client);   //��ô��ڵĳߴ�
	m_cacheDC.CreateCompatibleDC(cDC);
	m_bgcDC.CreateCompatibleDC(cDC);
	m_tempcDC.CreateCompatibleDC(cDC);
	m_tempBitmap.CreateCompatibleBitmap(cDC, m_client.Width(), m_client.Height());
	m_bgBitmap.LoadBitmap(IDB_BITMAP1);
	m_cacheDC.SelectObject(&m_tempBitmap);
	ReleaseDC(cDC);

	bird[0][0].LoadBitmap(IDB_BITMAP2);
	bird[0][1].LoadBitmap(IDB_BITMAP3);
	bird[0][2].LoadBitmap(IDB_BITMAP4);
	bird[1][0].LoadBitmap(IDB_BITMAP5);
	bird[1][1].LoadBitmap(IDB_BITMAP6);
	bird[1][2].LoadBitmap(IDB_BITMAP7);
	bird[2][0].LoadBitmap(IDB_BITMAP8);
	bird[2][1].LoadBitmap(IDB_BITMAP9);
	bird[2][2].LoadBitmap(IDB_BITMAP10);

	SetTimer(1, 60, NULL);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CFrameWnd::PreCreateWindow(cs))
		return FALSE;
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	cs.style = WS_OVERLAPPED | WS_CAPTION | FWS_ADDTOTITLE
		;

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);
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

void CMainFrame::OnSetFocus(CWnd* /*pOldWnd*/)
{
	// ������ǰ�Ƶ���ͼ����
	m_wndView.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// ����ͼ��һ�γ��Ը�����
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	// ����ִ��Ĭ�ϴ���
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}



void CMainFrame::OnTimer(UINT_PTR nID)
{
	CDC *cDC = this->GetDC();//��õ�ǰ���ڵ�DC   
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	static int x, y, dis_state = 2;;
	static double Time = 0;
	static int fly_state = 0;
	x = (x + 4) % 51;
	bg_state = 0;
	m_bgcDC.SelectObject(&m_bgBitmap);
	//pic.bg[bg_state].TBlt(0, 0, &m_cacheDC, &m_bgcDC);//����
	pic.bg[bg_state].TBlt(0, 0, &m_cacheDC, &m_bgcDC);//����
	//pipe.draw(pic, &m_cacheDC, &m_bgcDC);//��������
	//land.draw(pic, &m_cacheDC, &m_bgcDC);//��·
	//bird.paint(&m_cacheDC, &m_tempcDC);
	//pic.pipe2_up.TBlt(0, 0, &m_cacheDC, &m_bgcDC);

	m_cacheDC.TransparentBlt(0, 400, 288, pic.land.y, &m_bgcDC, pic.land.pos_x * 1024 + x, pic.land.pos_y * 1024, 288, pic.land.y, RGB(0, 0, 0));

	m_tempcDC.SelectObject(&bird[0][fly_state]);
	m_cacheDC.TransparentBlt(65, 230 + y, 48, 48, &m_tempcDC, 9.936, 9.936 + dis_state * 48, 48, 48, RGB(0, 0, 0));

	y = 4 * sin(Time*PI);
	Time += 0.25;
	fly_state = (fly_state + 1) % 3;
	int copy = goals, wei = 1;//��ʾ����
	int this_wei, first_pos = 142 - 12 * wei - wei / 2;
	pic.font[0].TBlt(first_pos + wei * 25, 60, &m_cacheDC, &m_bgcDC);//����



	//pic.text_ready.TBlt(50, 140, &m_cacheDC, &m_bgcDC);//readyͼ��
	//pic.tutorial.TBlt(85, 220, &m_cacheDC, &m_bgcDC);//ָʾpic.font[this_wei].TBlt(first_pos+wei*25,60,&m_cacheDC,&m_bgcDC);//����



	//pic.text_ready.TBlt(50, 140, &m_cacheDC, &m_bgcDC);//readyͼ��
	//pic.tutorial.TBlt(85, 220, &m_cacheDC, &m_bgcDC);//ָʾ


	piepeMove(pic, &m_cacheDC, &m_bgcDC);


	m_cacheDC.SelectObject(&m_tempBitmap);
	cDC->BitBlt(0, 0, m_client.Width(), m_client.Height(), &m_cacheDC, 0, 0, SRCCOPY);

	ReleaseDC(cDC);
	CFrameWnd::OnTimer(nID);
}

void CMainFrame::piepeMove(Pic &All, CDC* To, CDC* From) {//���ƺ���
	int count = pipes.GetCount();
	for (int i = 0; i<count; i++) {
		Pipe temp = pipes.GetHead();
		pipes.RemoveHead();
		temp.logic();
		

		if (temp.pos_x < -60) {
			temp.pos_x = 300;
		}

		pipes.AddTail(temp);
		All.pipe_down.TBlt(temp.pos_x, temp.pos_y, To, From);//������
		All.pipe_up.TBlt(temp.pos_x, temp.pos_y + 420, To, From);//������
	}
}
