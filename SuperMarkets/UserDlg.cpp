// UserDlg.cpp : implementation file
//

#include "stdafx.h"
#include "supermarkets.h"
#include "UserDlg.h"
#include "adoconn.h"
#include "newuserdlg.h"
#include "StorageDlg.h"
#include "Ticketdlg.h"
#include "Goodsdlg.h"
#include "settlementdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserDlg dialog


CUserDlg::CUserDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUserDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUserDlg)
	m_info = _T("");
	//}}AFX_DATA_INIT
}


void CUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUserDlg)
	DDX_Control(pDX, IDC_COMBO1, m_index);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_INFO, m_info);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUserDlg, CDialog)
	//{{AFX_MSG_MAP(CUserDlg)
	ON_BN_CLICKED(IDC_SELECT, OnSelect)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_MODFY, OnModfy)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_COMMAND(IDUM_STORAGE,OnStorage)
	ON_COMMAND(IDUM_TICKET,OnTicket)
	ON_COMMAND(IDUM_GOODS,OnNGoods)
	ON_COMMAND(IDUM_COUNT,OnCount)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUserDlg message handlers

BOOL CUserDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
		m_ImageList.Create(32,32,ILC_COLOR24|ILC_MASK,1,1);
	//��ͼ���б������ͼ��
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_USER));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_STORAGE));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_SALE));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_GOODS));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_COUNT));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_EXIT));
	
	UINT array[8];
	for(int i=0;i<7;i++)
	{
		if(i==4 || i==6)
			array[i] = ID_SEPARATOR; //��3��6����ťΪ�ָ���
		else
			array[i] = i+IDUM_USER;
	}
	array[7] = IDOK;
	m_ToolBar.Create(this);
	m_ToolBar.SetButtons(array,8);
	//����ͼ���б�
	m_ToolBar.GetToolBarCtrl().SetImageList(&m_ImageList);
	m_ToolBar.SetSizes(CSize(50,60),CSize(32,32)); //���ð�ť��ͼ��Ĵ�С
	//���ù�������ť����ʾ�ı�
	m_ToolBar.SetButtonText(0,"Ա������");
	m_ToolBar.SetButtonText(1,"�ֿ����");
	m_ToolBar.SetButtonText(2,"Ʊ�����");
	m_ToolBar.SetButtonText(3,"��Ʒ����");
	m_ToolBar.SetButtonText(5,"Ӫҵͳ��");
	m_ToolBar.SetButtonText(7,"�˳�ϵͳ");
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);



	m_list.SetExtendedStyle(LVS_EX_FLATSB
		|LVS_EX_FULLROWSELECT
		|LVS_EX_HEADERDRAGDROP
		|LVS_EX_ONECLICKACTIVATE
		|LVS_EX_GRIDLINES);
	m_list.InsertColumn(0,"Ա�����",LVCFMT_LEFT,70,1);
	m_list.InsertColumn(1,"����",LVCFMT_LEFT,50,4);
	m_list.InsertColumn(2,"Ȩ��",LVCFMT_LEFT,38,6);   
	m_list.InsertColumn(3,"ְλ",LVCFMT_LEFT,60,5);
	m_list.InsertColumn(4,"����",LVCFMT_LEFT,57,5);
	m_list.InsertColumn(5,"�Ա�",LVCFMT_LEFT,38,1);
	m_list.InsertColumn(6,"���֤��",LVCFMT_LEFT,120,1);
	m_list.InsertColumn(7,"��ϵ��ʽ",LVCFMT_LEFT,80,1);
	m_list.InsertColumn(8,"��ְʱ��",LVCFMT_LEFT,85,1);
	m_list.InsertColumn(9,"��ͥסַ",LVCFMT_LEFT,190,1);


	m_index.InsertString(0,"����");
	m_index.InsertString(1,"����");
	m_index.InsertString(2,"�Ա�");
	m_index.InsertString(3,"ְλ");
	m_index.InsertString(4,"Ȩ��");
	m_index.InsertString(5,"���֤��");
	m_index.InsertString(6,"��ϵ��ʽ");
	m_index.InsertString(7,"��ͥסַ");

	m_index.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CUserDlg::OnSelect() 
{
	// TODO: Add your control notification handler code here
	m_list.DeleteAllItems();
	CString sql;
	int intInfo; 
	UpdateData(true);
	int index = m_index.GetCurSel();
	switch(index)
	{
	case 0:
		sql.Format("select * from WORKER where WorkerID = '%s'",m_info);
		break;
	case 1:
		sql.Format("select * from WORKER where Name = '%s'",m_info);
		break;
	case 2:
		if(!m_info.Compare("��"))
			sql.Format("select * from WORKER where Sex = 1");
		else
			sql.Format("select * from WORKER where Sex = 0");
		break;
	case 3:
		sql.Format("select * from WORKER where WorkerPosition = '%s'",m_info);
		break;
	case 4:
		intInfo = atoi(m_info);
		sql.Format("select * from WORKER where Permissions = %d",intInfo);
		break;
	case 5:
		sql.Format("select * from WORKER where ID = '%s'",m_info);
		break;
	case 6:
		sql.Format("select * from WORKER where Phone = '%s'",m_info);
		break;
	case 7:
		sql.Format("select * from WORKER where Address = '%s'",m_info);
		break;
	}
	ADOConn adoConn;
	adoConn.OnInitADOConn();
	adoConn.m_pRecordset = adoConn.GetRecordSet((_bstr_t)sql);
	CString workid,name,Permissions,sex,id,phone,address,pwd;
	int i = 0;
	while(!adoConn.m_pRecordset->adoEOF)
	{
		m_list.InsertItem(i,"");
		m_list.SetItemText(i,0,(char *)(_bstr_t)adoConn.m_pRecordset->GetCollect("WorkerID"));
		m_list.SetItemText(i,1,(char *)(_bstr_t)adoConn.m_pRecordset->GetCollect("PWD"));
		m_list.SetItemText(i,2,(char *)(_bstr_t)adoConn.m_pRecordset->GetCollect("Permissions"));
		m_list.SetItemText(i,3,(char *)(_bstr_t)adoConn.m_pRecordset->GetCollect("WorkerPosition"));
		m_list.SetItemText(i,4,(char *)(_bstr_t)adoConn.m_pRecordset->GetCollect("Name"));
		CString strSex = (char *)(_bstr_t)adoConn.m_pRecordset->GetCollect("Sex");
		int bMan = atoi(strSex);
		if(bMan)
			m_list.SetItemText(i,5,"��");
		else
			m_list.SetItemText(i,5,"Ů");
		m_list.SetItemText(i,6,(char *)(_bstr_t)adoConn.m_pRecordset->GetCollect("ID"));
		m_list.SetItemText(i,7,(char *)(_bstr_t)adoConn.m_pRecordset->GetCollect("Phone"));
		m_list.SetItemText(i,8,(char *)(_bstr_t)adoConn.m_pRecordset->GetCollect("StartTime"));
		m_list.SetItemText(i,9,(char *)(_bstr_t)adoConn.m_pRecordset->GetCollect("Address"));
	
		adoConn.m_pRecordset->MoveNext();
	}
}


void CUserDlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	CTime time = CTime::GetCurrentTime();
	CNewUserDlg dlg;
	dlg.m_adress		= "";
	dlg.m_id			= "";
	dlg.m_male			= 0;
	dlg.m_phone			= "";
	dlg.m_workerid		= CountWorkerID(time);
	dlg.m_pwd			= "";
	dlg.m_Permissions	= 1;
	dlg.m_position		= "";

ERROR_END:	
	if(dlg.DoModal() == IDOK)
	{
		if((dlg.m_adress == "" || dlg.m_id == "" || dlg.m_phone == "" || dlg.m_workerid == ""|| \
				dlg.m_pwd == ""||dlg.m_position == "") )
		{
				MessageBox("����Ա����Ϣ���걸����������д��\n\r ��ȷ����Ϣ��������顱��");
				goto ERROR_END;
		}
		else
		{
			if(CheckExit("WorkerID",dlg.m_workerid,"WORKER"))
			{
				MessageBox("Ա�����Ѿ����ڣ����ѯ��");
				return;
			}
			else
			{
				ADOConn adoConn;
				adoConn.OnInitADOConn();
				CString sql;
				sql.Format("insert into WORKER(WorkerID,PWD,Permissions,Name,Sex,ID,Address,Phone,WorkerPosition,StartTime)\
				values('%s','%s',%d,'%s',%d,'%s','%s','%s','%s',#%s#)",dlg.m_workerid,dlg.m_pwd,dlg.m_Permissions,dlg.m_name,1 - dlg.m_male,dlg.m_id,\
				dlg.m_adress,dlg.m_phone,dlg.m_position,time.Format("%Y-%m-%d"));
				adoConn.ExecuteSQL((_bstr_t)sql);
				adoConn.ExitConnect();
			}
		}
	}

	OnSelect();
	
}

void CUserDlg::OnModfy() 
{
	// TODO: Add your control notification handler code here
	CTime time = CTime::GetCurrentTime();
	CNewUserDlg dlg;
	dlg.m_workerid		=	m_list.GetItemText(m_listIndex,0);
	dlg.m_pwd			=	m_list.GetItemText(m_listIndex,1);
	dlg.m_Permissions	=	atoi(m_list.GetItemText(m_listIndex,2));
	dlg.m_position		=	m_list.GetItemText(m_listIndex,3);
	dlg.m_name			=	m_list.GetItemText(m_listIndex,4);
	dlg.m_id			=	m_list.GetItemText(m_listIndex,6);
	dlg.m_phone			=	m_list.GetItemText(m_listIndex,7);
	dlg.m_adress		=	m_list.GetItemText(m_listIndex,8);

	if(m_list.GetItemText(m_listIndex,4).Compare("��"))
		dlg.m_male			=	0;
	else
		dlg.m_male			=	1;

	if(dlg.DoModal() ==  IDOK)
	{
		ADOConn adoConn;
		adoConn.OnInitADOConn();
		CString sql;
		sql.Format("UPDATE WORKER set PWD ='%s', Permissions =%d, Name='%s', Sex =%d, ID ='%s', Address ='%s',Phone ='%s',\
		WorkerPosition='%s', StartTime =#%s# where WorkerID = '%s'" ,dlg.m_pwd,dlg.m_Permissions,dlg.m_name,1 - dlg.m_male,dlg.m_id,\
		dlg.m_adress,dlg.m_phone,dlg.m_position,time.Format("%Y-%m-%d"),dlg.m_workerid);
		adoConn.ExecuteSQL((_bstr_t)sql);
		adoConn.ExitConnect();
	}
	OnSelect();
}

void CUserDlg::OnDelete() 
{
	// TODO: Add your control notification handler code here
	CString msg;
	msg.Format("���Ҫɾ��Ա����%s",m_list.GetItemText(m_listIndex,4));
	if(MessageBox(msg,"ɾ��Ա��",MB_OKCANCEL) != 1)
		return;
	
	ADOConn adoConn;
	adoConn.OnInitADOConn();
	CString workerID = m_list.GetItemText(m_listIndex,0);
	CString sql;
	sql.Format("delete * from WORKER where WorkerID = '%s'",workerID);
	
	adoConn.ExecuteSQL((_bstr_t)sql);
	adoConn.ExitConnect();	
	OnSelect();
}

void CUserDlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	m_listIndex =	m_list.GetSelectionMark();
	*pResult = 0;
}

void CUserDlg::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	
	if( m_index.GetCurSel() == 2)
	{
		m_info = "��";
		UpdateData(false);
	}
}

bool CUserDlg::CheckExit(CString index, CString value, CString table)
{
	ADOConn adoConn;
	adoConn.OnInitADOConn();
	CString sql;
	sql.Format("select * from %s where %s = '%s'",table,index,value);
		adoConn.m_pRecordset = adoConn.GetRecordSet((_bstr_t)sql);
	if(!adoConn.m_pRecordset->adoEOF)
	{
		return true;
	}
	else
	{
		return false;
	}
	adoConn.ExitConnect();

}

CString CUserDlg::CountWorkerID(CTime time)
{
	CString sql,ph,ticketID;
	sql.Format("select * from WORKER");
	ADOConn adoConn;
	adoConn.OnInitADOConn();
	adoConn.m_pRecordset = adoConn.GetRecordSet((_bstr_t)sql);
	if(!adoConn.m_pRecordset->adoEOF)
	{
		while(!adoConn.m_pRecordset->adoEOF)
		{
			ph = (char*)(_bstr_t)adoConn.m_pRecordset->GetCollect("WorkerID");
			adoConn.m_pRecordset->MoveNext();
		}
		ticketID.Format("%s%04d",time.Format("%y%m%d"),atoi(ph.Right(4))+1);
	}
	else
	{
		ticketID.Format("%s0001",time.Format("%y%m%d"));
	}
	adoConn.ExitConnect();
	return ticketID;
}

void CUserDlg::OnStorage()
{
	if(m_WorkType != 4 && m_WorkType  < 6)
	{
		MessageBox("��û��Ȩ�޷������ģ��");
		return;
	}
	OnOK();
	CStorageDlg dlg;
	dlg.m_WorkType = m_WorkType;
	dlg.DoModal();
	
}

void CUserDlg::OnTicket()
{
	if(m_WorkType != 3 && m_WorkType  < 6)
	{
		MessageBox("��û��Ȩ�޷������ģ��");
		return;
	}
	OnOK();
	CTicketDlg dlg;
	dlg.m_WorkType = m_WorkType;
	dlg.DoModal();
}

void CUserDlg::OnNGoods()
{
	if(m_WorkType != 2 && m_WorkType  < 6)
	{
		MessageBox("��û��Ȩ�޷������ģ��");
		return;
	}
	OnOK();
	CGoodsDlg dlg;
	dlg.m_WorkType = m_WorkType;
	dlg.DoModal();
}

void CUserDlg::OnCount()
{
	if(m_WorkType  < 6)
	{
		MessageBox("��û��Ȩ�޷������ģ��");
		return;
	}
	OnOK();
	CSettlementDlg dlg;
	dlg.m_WorkType = m_WorkType;
	dlg.DoModal();
}
