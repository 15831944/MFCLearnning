
// ListDirectoryFilesDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ListDirectoryFiles.h"
#include "ListDirectoryFilesDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CListDirectoryFilesDlg �Ի���



CListDirectoryFilesDlg::CListDirectoryFilesDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LISTDIRECTORYFILES_DIALOG, pParent)	
	, m_logIsShow(FALSE)
	, m_chanPath(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CListDirectoryFilesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_BTN_BACK, m_btnBack);
	DDX_Control(pDX, IDC_BTN_FWARD, m_btnFward);
	DDX_Control(pDX, IDC_BTN_DOWN, m_btnDown);
	DDX_Control(pDX, IDC_BTN_UP, m_btnUp);
}

BEGIN_MESSAGE_MAP(CListDirectoryFilesDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_SEARCH, &CListDirectoryFilesDlg::OnBnClickedSearch)
	//	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CListDirectoryFilesDlg::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_BTN_DOWN, &CListDirectoryFilesDlg::OnBnClickedBtnDown)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &CListDirectoryFilesDlg::OnNMDblclkList1)
	ON_BN_CLICKED(IDC_BTN_BACK, &CListDirectoryFilesDlg::OnBnClickedBtnBack)
	ON_BN_CLICKED(IDC_BTN_FWARD, &CListDirectoryFilesDlg::OnBnClickedBtnFward)
	ON_EN_CHANGE(IDC_PATH, &CListDirectoryFilesDlg::OnEnChangePath)
	ON_BN_CLICKED(IDC_BTN_UP, &CListDirectoryFilesDlg::OnBnClickedBtnUp)
	ON_MESSAGE(WM_SENDPATH, OnGetPath)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CListDirectoryFilesDlg ��Ϣ�������
int CALLBACK CompareFunc(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort) {

	int row1 = (int)lParam1;//����Ĳ���ʵ����SetItemData�������õ�ֵ���Ƚϵĵ�һ��
	int row2 = (int)lParam2;//����Ĳ���ʵ����SetItemData�������õ�ֵ���Ƚϵĵڶ���
	CListCtrl* lc = (CListCtrl*)lParamSort;
	CString s1 = lc->GetItemText(row1, 2);
	CString s2 = lc->GetItemText(row2, 2);

	// �Ƚϣ��Բ�ͬ���У���ͬ�Ƚϣ�ע���¼ǰһ����������һ��Ҫ�෴����		 
	if (s1.Compare(_T("�ļ���")) == 0)
		return  -1;
	else
	{
		return  1;
	}
}

BOOL CListDirectoryFilesDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_logIsShow = 0;
	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	m_list.InsertColumn(0, _T("����"), LVCFMT_LEFT, 340);
	m_list.InsertColumn(1, _T("�޸�����"), LVCFMT_LEFT, 180);
	m_list.InsertColumn(2, _T("����"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(3, _T("��С"), LVCFMT_LEFT, 100);
	m_list.SetExtendedStyle(m_list.GetExtendedStyle()
		| LVS_EX_FULLROWSELECT
		| LVS_EX_GRIDLINES);
	SetDlgItemText(IDC_PATH, _T("d:"));

	ListFiles(_T("d:\\*.*"));
	for (int i = 0; i < m_list.GetItemCount(); i++)
	{

		m_list.SetItemData(i, i);//������ǰһ���������������ÿ��ֵ���������Զ�������

	}
	m_list.SortItems(CompareFunc, (DWORD)&m_list);

	m_btnUp.EnableWindow(FALSE);
	m_btnBack.EnableWindow(FALSE);
	m_btnFward.EnableWindow(FALSE);
	m_btnDown.EnableWindow(FALSE);

	if (m_logPh == NULL) {
		m_logPh = new CLogPath();
		m_logPh->Create(IDD_LOG_PATH, AfxGetApp()->GetMainWnd());
	}

	CRect rect;

	rect.left = theApp.GetProfileIntW(_T("CRECT"), _T("Left"), 200);
	rect.top = theApp.GetProfileIntW(_T("CRECT"), _T("top"), 300);
	rect.right = theApp.GetProfileIntW(_T("CRECT"), _T("right"), 400);
	rect.bottom = theApp.GetProfileIntW(_T("CRECT"), _T("bottom"), 400);

	MoveWindow(rect, FALSE);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CListDirectoryFilesDlg::ListFiles(CString  path) {



	CFileFind ff;

	if (path.IsEmpty())
	{
		path = _T("c:\\*.*");
	}

	BOOL bworking = ff.FindFile(path);

	if (bworking)
	{
		m_list.DeleteAllItems();
	}

	CString fileName, fileLen, lastTime, fileType;
	int i = 0;
	while (bworking) {

		bworking = ff.FindNextFileW();

		if (ff.IsHidden() || ff.IsSystem()) {
			continue;
		}

		fileName = ff.GetFileName();
		if (fileName == _T(".") || fileName == _T("..")) {
			continue;
		}
		if (ff.IsDirectory()) {
			fileType = _T("�ļ���");
			fileLen = _T("");
		}
		else {
			int dot = ff.GetFilePath().ReverseFind('.');
			fileType = ff.GetFilePath().Mid(dot);
			ULONGLONG	size = ff.GetLength();
			fileLen.Format(_T("%dKB"), size / 1024 + 1);
		}



		CTime time;
		ff.GetLastWriteTime(time);

		lastTime = time.Format(_T("%y-%m-%d %H:%M:%S"));

		m_list.InsertItem(i, fileName);
		m_list.SetItemText(i, 1, lastTime);
		m_list.SetItemText(i, 2, fileType);
		m_list.SetItemText(i, 3, fileLen);


	}

}

void CListDirectoryFilesDlg::OnPaint()
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
HCURSOR CListDirectoryFilesDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CListDirectoryFilesDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���

	//CDialogEx::OnOK();
}


void CListDirectoryFilesDlg::OnCancel()
{
	// TODO: �ڴ����ר�ô����/����û���

	//CDialogEx::OnCancel();
}


void CListDirectoryFilesDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	DestroyWindow();

	//CDialogEx::OnClose();
}

void CListDirectoryFilesDlg::ShowList() {
	CString path;
	GetDlgItemText(IDC_PATH, path);



	ListFiles(path + _T("//*.*"));

	for (int i = 0; i < m_list.GetItemCount(); i++)
	{

		m_list.SetItemData(i, i);//������ǰһ���������������ÿ��ֵ���������Զ�������

	}
	m_list.SortItems(CompareFunc, (DWORD)&m_list);
}

void CListDirectoryFilesDlg::OnBnClickedSearch()
{
	CString path;
	GetDlgItemText(IDC_PATH, path);

	int lastIdx = path.ReverseFind('/');

	CString str1 = path.Mid(lastIdx + 1);
	m_logPh->m_listBox.AddString(str1);

	m_vecPath.push_back(path);


	int m = m_logPh->m_listBox.GetCount();

	if (m > 0) {
		m_btnDown.EnableWindow(TRUE);

		if (m > 5) {
			m_vecPath.erase(m_vecPath.begin(), m_vecPath.begin() + 1);
			m_logPh->m_listBox.DeleteString(0);
			m = m_logPh->m_listBox.GetCount();
			m_logPh->m_listBox.SetCurSel(m - 1);
		}

		SetBtnEnable(m - 1,m);

	}
	else {
		m_btnDown.EnableWindow(FALSE);

	}

	ShowList();

}

void CListDirectoryFilesDlg::OnBnClickedBtnDown()
{
	CRect rec;

	m_btnDown.GetWindowRect(rec);
	if (m_logIsShow == 0)
	{
		if (m_logPh == NULL) {
			m_logPh = new CLogPath();
			m_logPh->Create(IDD_LOG_PATH, AfxGetApp()->GetMainWnd());
			m_logPh->ShowWindow(SW_NORMAL);
			m_logPh->SetWindowPos(&this->wndTopMost, rec.left - 70, rec.top + 40, 160, 250, SWP_SHOWWINDOW);

		}
		else {
			m_logPh->ShowWindow(SW_NORMAL);
			m_logPh->SetWindowPos(&this->wndTopMost, rec.left - 70, rec.top + 40, 160, 250, SWP_SHOWWINDOW);
		}
		m_logIsShow = 1;
	}
	else {
		if (m_logPh != NULL) {

			m_logIsShow = m_logPh->ShowWindow(SW_HIDE);
			m_logIsShow = 0;
		}
	}


}

LRESULT CListDirectoryFilesDlg::OnGetPath(WPARAM wParam, LPARAM iParam)
{
	int idex = (int)iParam;

	CString str = m_vecPath[idex];

	SetDlgItemText(IDC_PATH, str);

	ShowList();

	return 0;
}


void CListDirectoryFilesDlg::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE active = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CString str1;
	CString str2;
	//str.Format(L"%d,%d", active->iItem, active->iSubItem);
	//MessageBox(str);
	if (active->iSubItem == 0) {

		int row = active->iItem;

		str1 = m_list.GetItemText(row, 0);
		str2 = m_list.GetItemText(row, 2);
	}

	if (str2.Compare(_T("�ļ���")) == 0) {
		CString oPath;
		GetDlgItemText(IDC_PATH, oPath);
		m_chanPath = oPath + _T("\/") + str1;
		SetDlgItemText(IDC_PATH, m_chanPath);

		m_logPh->m_listBox.AddString(str1);

		m_vecPath.push_back(m_chanPath);

	}
	int m = m_logPh->m_listBox.GetCount();
	m_logPh->m_listBox.SetCurSel(m - 1);
	if (m > 0) {
		m_btnDown.EnableWindow(TRUE);

		if (m > 5) {
			m_vecPath.erase(m_vecPath.begin(), m_vecPath.begin() + 1);
			m_logPh->m_listBox.DeleteString(0);
			m = m_logPh->m_listBox.GetCount();
			m_logPh->m_listBox.SetCurSel(m - 1);
		}

		SetBtnEnable(m - 1, m);

	}
	else {
		m_btnDown.EnableWindow(FALSE);

	}

	ShowList();
	*pResult = 0;
}


void CListDirectoryFilesDlg::OnBnClickedBtnBack()
{
	int total = m_logPh->m_listBox.GetCount();
	int index = m_logPh->m_listBox.GetCurSel();

	if (index == 0)
		return;

	m_logPh->m_listBox.SetCurSel(index - 1);

	CString selStr;
	m_logPh->m_listBox.SelectString(index - 1, selStr);

	CString getStr = m_vecPath[index - 1];

	SetDlgItemText(IDC_PATH, getStr);

	SetBtnEnable(index - 1,total);
	ShowList();

}
void CListDirectoryFilesDlg::SetBtnEnable(int index,int total) {

	if (index == 0&&total>1) {
		m_btnBack.EnableWindow(FALSE);
		m_btnFward.EnableWindow(TRUE);
	}
	else if (index == total-1&&total>1)
	{
		m_btnFward.EnableWindow(FALSE);
		m_btnBack.EnableWindow(TRUE);
	}
	else if (index > 0 && index <total-1) {
		m_btnBack.EnableWindow(TRUE);
		m_btnFward.EnableWindow(TRUE);
	}
	
}


void CListDirectoryFilesDlg::OnBnClickedBtnFward()
{
	int index = m_logPh->m_listBox.GetCurSel();
	int total = m_logPh->m_listBox.GetCount();
	if (index >= total-1)
		return;

	m_logPh->m_listBox.SetCurSel(index + 1);

	CString selStr;
	m_logPh->m_listBox.SelectString(index + 1, selStr);

	CString getStr = m_vecPath[index + 1];

	SetDlgItemText(IDC_PATH, getStr);



	SetBtnEnable(index + 1,total);
	ShowList();
}


void CListDirectoryFilesDlg::OnEnChangePath()
{
	CString path;
	GetDlgItemText(IDC_PATH, path);

	int index = path.Find('\/', 0);

	if (index > -1) {
		m_btnUp.EnableWindow(TRUE);
	}
	else {
		m_btnUp.EnableWindow(FALSE);

	}
	
}


void CListDirectoryFilesDlg::OnBnClickedBtnUp()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString path;
	GetDlgItemText(IDC_PATH, path);

	int index = path.ReverseFind('\/');
	if (index < 0) {
		return;
	}
	CString str = path.Mid(0, index);

	SetDlgItemText(IDC_PATH, str);

	ShowList();

}


void CListDirectoryFilesDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������

	CRect rect;

	::GetWindowRect(AfxGetApp()->GetMainWnd()->GetSafeHwnd(),rect);

	theApp.WriteProfileInt(_T("CRECT"), _T("LEFT"), rect.left);
	theApp.WriteProfileInt(_T("CRECT"), _T("RIGHT"), rect.right);
	theApp.WriteProfileInt(_T("CRECT"), _T("TOP"), rect.top);
	theApp.WriteProfileInt(_T("CRECT"), _T("BOTTOM"), rect.bottom);


}
