#include "stdafx.h"
#include "XmlHelper.h"


CXmlHelper::CXmlHelper()
{
	::CoInitialize(NULL);
	HRESULT hr = m_pDoc.CreateInstance(MSXML2::CLSID_DOMDocument);

	if (!SUCCEEDED(hr))
	{
		_com_error er(hr);
		MessageBox(AfxGetMainWnd()->m_hWnd, er.ErrorMessage(), _T("����"), MB_ICONERROR);
		return;
	}

}


CXmlHelper::~CXmlHelper()
{
}
void CXmlHelper::ReadXml(CString strXmlPath, MSXML2::IXMLDOMNodeListPtr &nodeList)
{
	// ��ȡxml
	m_pDoc->put_async(VARIANT_FALSE);
	VARIANT_BOOL bhr = m_pDoc->load((_variant_t)strXmlPath);

	if (bhr != VARIANT_TRUE) {
		MessageBox(AfxGetMainWnd()->m_hWnd, _T("�޷���ȷ��ȡxml�ļ�"), _T("����"), MB_ICONERROR);
		return;
	}

	// ���ڵ�ȡ��
	MSXML2::IXMLDOMNodePtr m_pXMLRoot = m_pDoc->documentElement;

	nodeList = m_pXMLRoot->childNodes;

	long i = nodeList->Getlength();
}

void CXmlHelper::ReadNode(const MSXML2::IXMLDOMNodeListPtr & nodeList, vector<CString>& nodes)
{
	if (nodeList == NULL) {
		return;
	}
	long j = nodeList->Getlength();
	CString strNode;


	for (int nodeCount = 0; nodeCount < nodeList->Getlength(); nodeCount++)
	{
		MSXML2::IXMLDOMNodePtr nodePtr = nodeList->nextNode();
		_variant_t strCaseNodeName = nodePtr->GetnodeName();
		_variant_t strCaseNodeValue = nodePtr->Gettext();

		BSTR bStrTemp = strCaseNodeName.bstrVal;
		CString strTemp = CString(bStrTemp);
		SysFreeString(bStrTemp);
		CString strNodeName = strTemp;

		
		if (0 == strNodeName.Compare(_T("node")))
		{
			strNode = (BSTR)strCaseNodeValue.pbstrVal;

			nodes.push_back(strNode);
		}
		if (0 == strNodeName.Compare(_T("Node")))
		{
			ReadNode(nodePtr->GetchildNodes(), nodes);
			continue;
		}
		ReadNode(nodePtr->GetchildNodes(), nodes);

	}

	/*for (MSXML2::IXMLDOMNodePtr pChild = pParent->firstChild; pChild != NULL; pChild = pChild->nextSibling) {

	}*/

}

