// MyTestDLL.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "MyTestDLL.h"


// ���ǵ���������һ��ʾ��
MYTESTDLL_API int nMyTestDLL=0;

// ���ǵ���������һ��ʾ����
MYTESTDLL_API int fnMyTestDLL(void)
{
    return 42;
}
MYTESTDLL_API CMyTestDLL * GetMyDll(int a)
{
	return new CMyTestDLL(a);
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� MyTestDLL.h
CMyTestDLL::CMyTestDLL(int m,int n)
{
	this->a = m;
	this->b = n;
}

CMyTestDLL::CMyTestDLL(int m)
{
	this->a = m;
}

int CMyTestDLL::sum()
{
	return a+b;
}
