
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
	, m_fileName(_T(""))
	, m_findOpen(FALSE)
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
	ON_COMMAND(ID_32771, &CMyNoteDlg::OnNewFile)
	ON_COMMAND(ID_32773, &CMyNoteDlg::OnSaveFile)
	ON_WM_DROPFILES()
	ON_COMMAND(ID_32774, &CMyNoteDlg::OnSaveAs)
	ON_COMMAND(ID_32776, &CMyNoteDlg::OnFind)
	ON_COMMAND(ID_32780, &CMyNoteDlg::OnFont)
	ON_COMMAND(ID_32777, &CMyNoteDlg::OnInsertDate)
	ON_MESSAGE(WM_FIND_EVENT, OnFindStr)
	ON_COMMAND(ID_32781, &CMyNoteDlg::OnCopyOther)
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

LRESULT CMyNoteDlg::OnFindStr(WPARAM wParam, LPARAM iParam)
{
	CEdit *edit = (CEdit*)GetDlgItem(IDC_EDIT1);	
	edit->SetSel((int)wParam, (int)iParam);
	edit->SetFocus();

	return 0;
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

	if (fDiaLog.DoModal() == IDOK) {
		CString pName = fDiaLog.GetPathName();
		m_fileName = pName;
		SetTitle();
		CFile file;
		char buffer[256];
		if (file.Open(pName, CFile::modeReadWrite, NULL)) {
			
			if (file.Read(buffer, 2) == 2)
			{
				switch (buffer[0])
				{
				case 0xBBEF:
					ReadUTF8(file);
					return;
				case 0xFFFE:
					ReadUnicode(file);
					return;
				}
			}
			ReadAnsi(file);
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


void CMyNoteDlg::OnNewFile()
{
	// TODO: �ڴ���������������

	SetWindowText(_T(""));

	CString txt;
	GetDlgItemText(IDC_EDIT1, txt);

	if (!m_fileName.IsEmpty() || !txt.IsEmpty()) {
		if (MessageBox(_T("�Ƿ񱣴�"), _T("�Ƿ񱣴�"), MB_OKCANCEL) == IDOK) {
			OnSaveFile();
			txt.Empty();
			SetDlgItemText(IDC_EDIT1, txt);
			m_fileName.Empty();
		}
		else {
			
			txt.Empty();
			SetDlgItemText(IDC_EDIT1, txt);
			m_fileName.Empty();
		}


	}


}


void CMyNoteDlg::OnSaveFile()
{
	CString txt;

	GetDlgItemText(IDC_EDIT1, txt);

	if (!m_fileName.IsEmpty())
	{
		CStdioFile file;
		if (file.Open(m_fileName, CFile::modeCreate|CFile::modeReadWrite, NULL) == TRUE) {
			
			char* old_locale = _strdup(setlocale(LC_CTYPE, NULL));

			setlocale(LC_CTYPE, "chs");//�趨

			file.WriteString(txt);
			file.Close();
		}
	}
	else if (m_fileName.IsEmpty()) {
		
		CFileDialog fDiaLog(FALSE, TEXT("*.txt"), _T("�½��ļ�"),
			OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
			_T("txt Files (*.txt)|*.txt|cs Files (*.cs)|*.cs|Data Files (*.ini)|*.ini|All Files (*.*)|*.*||"), NULL);

		if (fDiaLog.DoModal() == IDOK) {
			CString pName = fDiaLog.GetPathName();
			m_fileName = pName;

			CStdioFile file;
			if (file.Open(pName, CFile::modeCreate|CFile::modeWrite, NULL)) {
			
				char* old_locale = _strdup(setlocale(LC_CTYPE, NULL));

				setlocale(LC_CTYPE, "chs");//�趨

				file.WriteString(txt);
				file.Close();
			
			}
		}

	}

}


void CMyNoteDlg::OnDropFiles(HDROP hDropInfo)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵv
	CDialogEx::OnDropFiles(hDropInfo);
	TCHAR sFile[256];
	int nCount = DragQueryFile(hDropInfo, 0, sFile, _countof(sFile));
	CFile file;
	if (!file.Open(sFile, CFile::modeRead))
	{//�ļ����϶����̱�ɾ���ˣ������ļ���ռ��
		AfxMessageBox(_T("���ļ�ʱʧ�ܣ������ļ������Ƿ���ȷ��"));
		return;
	}
	if (file.Read(sFile, 2) == 2)
	{
		switch (sFile[0])
		{
		case 0xBBEF:
			ReadUTF8(file);
			return;
		case 0xFFFE:
			ReadUnicode(file);
			return;
		}
	}
	ReadAnsi(file);
	
	
}
void CMyNoteDlg::ReadAnsi(CFile& file)//��ȡ��ʽ1��ANSI //����������
{
	file.Seek(0, CFile::begin);//�ص�ͷ��ʼ
	char buff[1024];
	UINT nRet = 0;//�����ļ���ANSI:խ�ַ��� Unicode:���ַ���Ҳ��UTF-16 UTF-8:խ�ַ���������Unicode 
	CString str;
	while (nRet = file.Read(buff, sizeof(buff) - 1))//nRet != 0
	{
		buff[nRet] = _T('\0');
		str += buff;
	}
	SetDlgItemText(IDC_EDIT1, str);
}

void CMyNoteDlg::ReadUTF8(CFile& file)//UTF-8�ļ������ȡ
{
	file.Seek(3, CFile::begin);//����ƶ������ֽ�
	LONGLONG nLen = file.GetLength();//64λ����ϵͳ
	char* p = new char[nLen + 1];
	nLen = file.Read(p, nLen);
	p[nLen] = '\0';
	TCHAR* pText = new TCHAR[nLen / 2 + 2];//��ֹ���� + 2
	nLen = MultiByteToWideChar(CP_UTF8, NULL, p, -1, pText, nLen / 2 + 2);//����p ���� pText
	SetDlgItemText(IDC_EDIT1, pText);
	delete[] p;
	delete[] pText;
}

void CMyNoteDlg::ReadUnicode(CFile& file)//Unicode�ļ������ȡ
{
	file.Seek(2, CFile::begin);//����ƶ������ֽ�
	LONGLONG nLen = file.GetLength();//64λ����ϵͳ
	TCHAR* pText = new TCHAR[nLen / 2 + 1];//��ֹ���� + 1
	nLen = file.Read(pText, nLen);
	pText[nLen / 2] = _T('\0');
	SetDlgItemText(IDC_EDIT1, pText);
	delete[] pText;
}

void CMyNoteDlg::OnSaveAs()
{
	// TODO: �ڴ���������������
	CString txt;
	GetDlgItemText(IDC_EDIT1, txt);

	CFileDialog fDiaLog(FALSE, TEXT("*.txt"), _T("�½��ļ�"),
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		_T("txt Files (*.txt)|*.txt|cs Files (*.cs)|*.cs|Data Files (*.ini)|*.ini|All Files (*.*)|*.*||"), NULL);

	if (fDiaLog.DoModal() == IDOK) {
		CString pName = fDiaLog.GetPathName();
		m_fileName = pName;

		CStdioFile file;
		if (file.Open(pName, CFile::modeCreate | CFile::modeWrite, NULL)) {

			char* old_locale = _strdup(setlocale(LC_CTYPE, NULL));

			setlocale(LC_CTYPE, "chs");//�趨

			file.WriteString(txt);
			file.Close();

		}
	}
}


void CMyNoteDlg::OnFind()
{
	// TODO: �ڴ���������������
	/*CEdit *edit = (CEdit*)GetDlgItem(IDC_EDIT1);
	CString str;
	GetDlgItemText(IDC_EDIT1, str);

	int index=str.Find(_T("abc"), 0);
	edit->SetSel(index, index + 3);*/
	if (!m_findOpen||m_diaFind.m_isClose==TRUE) {
		m_findOpen=m_diaFind.Create(IDD_DIALOG_FIND, this);
		m_diaFind.ShowWindow(SW_SHOWNORMAL);
		m_diaFind.m_isClose = FALSE;
		GetDlgItemText(IDC_EDIT1, m_diaFind.m_totalStr);
	}
	
	
}


void CMyNoteDlg::OnFont()
{
	CFont* pFont = GetDlgItem(IDC_EDIT1)->GetFont();
	LOGFONT lf;
	pFont->GetLogFont(&lf);//��õ�ǰCFont�����LOGFONT�ṹ��Ŀ���
	CFontDialog fd(&lf);//��������Ի��򣬳�ʼѡ������Ϊ��ǰCFont���������

	if (IDCANCEL == fd.DoModal())
		return;
	m_font.DeleteObject();//���m_font�Ѿ�������һ��������Դ�������ͷ���
	m_font.CreateFontIndirect(fd.m_cf.lpLogFont);//ʹ��ѡ�������LOGFONT�����µ����� 
												 //	m_font.CreateFontIndirect(&lf);
	GetDlgItem(IDC_EDIT1)->SetFont(&m_font);//ѡ������
}

void CMyNoteDlg::SetTitle()
{
	CString str;
	if (m_fileName.IsEmpty())
		str = "�ޱ���";
	else
		str = m_fileName;

	int i = str.ReverseFind('\\'); //�����ҵ� \\
								   	if(i > 0)
	str = str.Mid(i + 1); //��\\λ�ô� �س�str���������

	SetWindowText(str);
}


void CMyNoteDlg::OnInsertDate()
{
	// TODO: �ڴ���������������
	COleDateTime time = COleDateTime::GetCurrentTime();
	CString str = time.Format(_T("%Y-%m-%d %H:%M"));
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
	pEdit->ReplaceSel(str);//ѡ�в���

}


void CMyNoteDlg::OnCopyOther()
{
	// TODO: Add your command handler code here

	//HWND	m_qqhWnd = ::FindWindow(_T("TXGuiFoundation"), _T("QQ"));
	HWND	padWnd = ::FindWindow(_T("Notepad"), NULL);
	if (padWnd)

	{

		//��ȡ���ھ��

		CRect rect;

		::GetWindowRect(padWnd, rect);

		CString str;

		CPoint user_pt;

		//��user_pt�㶨λ���༭�����
		user_pt.x = rect.left + 63;

		user_pt.y = rect.top + 89;

		//��ȡedit������
		HWND editWnd = ::WindowFromPoint(user_pt);
		
		//��ȡ���ֳ���
		LRESULT res = ::SendMessage(editWnd, WM_GETTEXTLENGTH, 0, 0);
		int len = (int)res;
		TCHAR *buf=new TCHAR[len+1];
		
		::SendMessage(editWnd, WM_GETTEXT, (WPARAM)res, (LPARAM)buf);
		buf[len] = '/0';
		SetDlgItemText(IDC_EDIT1, buf);
			
		delete[]buf;
	}
	else
		MessageBox(_T("���Ҵ���ʧ�ܣ�"));
	
}
