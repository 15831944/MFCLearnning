// MyDLL.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "MyDLL.h"


// ���ǵ���������һ��ʾ��
MYDLL_API int nMyDLL=0;

// ���ǵ���������һ��ʾ����
MYDLL_API int fnMyDLL(void)
{
    return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� MyDLL.h
CMyDLL::CMyDLL()
{
    return;
}

int CMyDLL::sum(int a, int b)
{
	m = a;
	n = b;
	return m + n;
}
