// UserTreeView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "UserTreeView.h"
#include"Resource.h"
#include"UserAdd.h"
#include"UserA.h"
#include"PwdChange.h"
#include<iterator>
#include"UserQuery.h"


extern CString G_LoginName;
// CUserTreeView

IMPLEMENT_DYNCREATE(CUserTreeView, CTreeView)

CUserTreeView::CUserTreeView()
{

}

CUserTreeView::~CUserTreeView()
{
}

BEGIN_MESSAGE_MAP(CUserTreeView, CTreeView)
	ON_COMMAND(ID_32775, &CUserTreeView::OnUserAdd)
	ON_COMMAND(ID_32773, &CUserTreeView::OnPwdChange)
	ON_COMMAND(ID_32777, &CUserTreeView::OnUserQuery)
END_MESSAGE_MAP()


// CUserTreeView ���

#ifdef _DEBUG
void CUserTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CUserTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// CUserTreeView ��Ϣ�������


void CUserTreeView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���



	imageList.Create(30, 30, ILC_COLOR32, 4, 4);


	CBitmap bitmap[4];

	bitmap[0].LoadBitmapW(IDB_BITMAP_DOCTOR);
	bitmap[1].LoadBitmapW(IDB_BITMAP_MANAGER);
	bitmap[2].LoadBitmapW(IDB_BITMAP_SAL);
	bitmap[3].LoadBitmapW(IDB_BITMAP_NORMAL);

	imageList.Add(&bitmap[0], RGB(0, 0, 0));
	imageList.Add(&bitmap[1], nullptr);
	imageList.Add(&bitmap[2], nullptr);
	imageList.Add(&bitmap[3], nullptr);


	CTreeCtrl & treeCtrl = GetTreeCtrl();
	treeCtrl.SetImageList(&imageList, TVSIL_NORMAL);

	//treeCtrl.InsertItem(TEXT("text"), 0, 0, NULL);

	CMedicAdminDoc *pDoc = (CMedicAdminDoc *)GetDocument();
	CUserSet * userSet = pDoc->GetUserSet();

	if (userSet->IsOpen() == FALSE) {
		userSet->Open(CRecordset::dynaset);
	}
	//TODO:�ĳɶ�xml����treeView�ĸ��ڵ�
	CString root[3] = {
		TEXT("ҽ��"),TEXT("����Ա"),TEXT("��ҩԱ")
	};

	int n = sizeof(root) / sizeof(root[0]);

	for (int i = 0; i < n; i++)
	{
		map<CString, vector<CUserA>> mapVec;
		vector<CUserA> vecUser;

		HTREEITEM item1 = treeCtrl.InsertItem(root[i], 3, 3, NULL);

		m_vecRoots.push_back(root[i]);

		CString filter;
		filter.Format(TEXT("classification='%s'"), root[i]);


		userSet->m_strFilter = filter;
		userSet->Requery();
		userSet->MoveFirst();

		while (!userSet->IsEOF())
		{
			CString addNode;

			addNode.Format(TEXT("%s(%s)"), CString(userSet->m_name), CString(userSet->m_account));

			if (G_LoginName == CString(userSet->m_name)) {

				CString str;

				str.Format(TEXT("[�ѵ�¼] %s"), addNode);

				treeCtrl.InsertItem(str, i, i, item1);
			}
			else {
				treeCtrl.InsertItem(addNode, i, i, item1);
			}
			CUserA userA;

			userA.m_type = root[i];
			userA.m_userAccount = userSet->m_account;
			userA.m_userName = userSet->m_name;
			userA.m_userPwd = userSet->m_password;

			vecUser.push_back(userA);
			userSet->MoveNext();
		}
		mapVec.insert(make_pair(root[i], vecUser));
		m_vecTreeList.push_back(mapVec);
	}

}

//����Ñ�
void CUserTreeView::OnUserAdd()
{
	// TODO: �ڴ���������������
	CUserAdd userAddDia;
	userAddDia.DoModal();

	if (userAddDia.m_isAdd) {

		POSITION pos = userAddDia.listUser.GetHeadPosition();

		while (pos != NULL) {

			CUserA u = userAddDia.listUser.GetAt(pos);

			CString userType = u.m_type;
			CString userName = u.m_userName;
			CString userAcount = u.m_userAccount;

			for (size_t m = 0; m < m_vecTreeList.size(); m++)
			{
				map<CString, vector<CUserA>>::iterator iter = m_vecTreeList[m].find(userType);
				if (iter != m_vecTreeList[m].end()) {

					iter->second.push_back(u);
					break;
				}
			}

			CString addNode;
			addNode.Format(TEXT("%s(%s)"), userName, userAcount);

			CTreeCtrl & treeCtrl = GetTreeCtrl();

			HTREEITEM item1 = treeCtrl.GetRootItem();
			CString strType = treeCtrl.GetItemText(item1);
			int i = 0;
			while (!strType.IsEmpty())
			{
				if (userType == strType) {

					treeCtrl.InsertItem(addNode, i, i, item1);

					break;
				}
				i++;
				item1 = treeCtrl.GetNextSiblingItem(item1);
				strType = treeCtrl.GetItemText(item1);

			}

			userAddDia.listUser.GetNext(pos);

		}
	}
}


void CUserTreeView::OnPwdChange()
{
	// TODO: �ڴ���������������

	bool isAdmin = false;

	CUserA curUser;
	CPwdChange pwdCh;

	//�жϵ�¼�û��Ƿ��ǹ���Ա
	for (size_t m = 0; m < m_vecTreeList.size(); m++)
	{
		map<CString, vector<CUserA>> mapVec = m_vecTreeList[m];


		bool flag = false;
		for (map<CString, vector<CUserA>>::iterator iter = mapVec.begin(); iter != mapVec.end(); iter++) {
			{

				vector <CUserA>tempVec = iter->second;

				for (size_t i = 0; i < tempVec.size(); i++)
				{
					CUserA tempUser = tempVec[i];

					if (tempUser.m_userName.Compare(G_LoginName) == 0) {

						if (iter->first.Compare(CString(TEXT("����Ա"))) == 0) {

							isAdmin = true;
						}
						else {
							curUser.m_type = tempUser.m_type;
							curUser.m_userAccount = tempUser.m_userAccount;
							curUser.m_userName = tempUser.m_userName;
							curUser.m_userPwd = tempUser.m_userPwd;
						}
						flag = true;
						break;
					}
				}
				if (flag) {
					break;
				}
			}
		}

		if (flag) {
			break;
		}
	}

	CTreeCtrl& treeCtrl = GetTreeCtrl();
	//����Ա���Ը��������˵����룬����ֻ�ܸ����Լ�������
	if (isAdmin) {
		HTREEITEM selItem = treeCtrl.GetSelectedItem();
		CString selText = treeCtrl.GetItemText(selItem);

		HTREEITEM parentItem = treeCtrl.GetParentItem(selItem);
		CString paText = treeCtrl.GetItemText(parentItem);
		CUserA u;

		for (size_t m = 0; m < m_vecTreeList.size(); m++)
		{
			map<CString, vector<CUserA>>::iterator iter = m_vecTreeList[m].find(paText);
			if (iter != m_vecTreeList[m].end()) {

				//iter->second.push_back(u);

				vector < CUserA>tempVec = iter->second;

				for (size_t i = 0; i < tempVec.size(); i++)
				{
					CUserA tempU = tempVec[i];

					CString text;
					text.Format(_T("%s(%s)"), tempU.m_userName, tempU.m_userAccount);
					CString text2;
					text2.Format(_T("[�ѵ�¼] %s(%s)"), tempU.m_userName, tempU.m_userAccount);
					if (text.Compare(selText) == 0 || text2.Compare(selText) == 0) {

						u.m_type = tempU.m_type;
						u.m_userAccount = tempU.m_userAccount;
						u.m_userName = tempU.m_userName;
						u.m_userPwd = tempU.m_userPwd;

						break;
					}
				}
				break;
			}
		}



		pwdCh.SetName(u.m_userName);
		pwdCh.SetAccount(u.m_userAccount);
		pwdCh.SetPwd(u.m_userPwd);
	}
	else {
		pwdCh.SetName(curUser.m_userName);
		pwdCh.SetAccount(curUser.m_userAccount);
		pwdCh.SetPwd(curUser.m_userPwd);
	}

	pwdCh.DoModal();

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


void CUserTreeView::OnUserQuery()
{
	// TODO: �ڴ���������������
	CUserQuery userQuery;
	CString condition;
	if (userQuery.DoModal() == IDOK) {
		condition = userQuery.GetCondition();

		int markRoot = 0, markChild = 0;
		CString strRoot, strChild;
		//�����Ñ�
		for (size_t m = 0; m < m_vecTreeList.size(); m++)
		{
			map<CString, vector<CUserA>> mapVec = m_vecTreeList[m];


			bool flag = false;
			for (map<CString, vector<CUserA>>::iterator iter = mapVec.begin(); iter != mapVec.end(); iter++) {
				{

					vector <CUserA>tempVec = iter->second;

					for (size_t i = 0; i < tempVec.size(); i++)
					{
						CUserA tempUser = tempVec[i];
						//���ҵ���
						if (tempUser.m_userName.Find(condition, 0) != -1 || tempUser.m_userAccount.Find(condition, 0) != -1) {
							markRoot = m;
							markChild = i;

							flag = true;
							break;
						}
					}
					if (flag) {
						break;
					}
				}
			}

			if (flag) {
				break;
			}
		}

		CTreeCtrl & treeCtrl = GetTreeCtrl();

		HTREEITEM node;
		HTREEITEM nextNode;
		
		//��ȡ��һ�����ڵ�
		node = treeCtrl.GetRootItem();
		nextNode = node;
		
		/*
		*��ȡÿ�����ڵ�������²�ĵ�һ���ڵ�
		*/
		vector<HTREEITEM>vecItem;

		while (nextNode != NULL) {

			//��ȡ�����²�ڵ��еĵ�һ���ڵ�
			while (node != NULL) {

				vecItem.push_back(node);
				node = treeCtrl.GetChildItem(node);
			}
			//����ĩ�˽ڵ㿪ʼ����ȡ���������ֵܽڵ㣬Ȼ���˻ص���һ���ظ��������
			for (int q = (int)vecItem.size() - 1; q > -1; q--)
			{

				HTREEITEM endItem = vecItem[q];

				HTREEITEM endItemSbiling = endItem;

				while (endItemSbiling != NULL) {

					CString itemText = treeCtrl.GetItemText(endItemSbiling);

					if (itemText.Find(condition) != -1) {

						treeCtrl.SelectItem(endItemSbiling);
						treeCtrl.Expand(endItemSbiling, TVM_EXPAND);
						vecItem.clear();
						return;

					}

					endItemSbiling = treeCtrl.GetNextItem(endItemSbiling, TVGN_NEXT);

				}
			}
			//ÿ���һ������
			vecItem.clear();

			//������ڵ���ֵܽڵ�
			nextNode = treeCtrl.GetNextItem(nextNode, TVGN_NEXT);
			node = nextNode;
		}
	}
}