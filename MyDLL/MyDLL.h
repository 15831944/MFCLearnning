// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� MYDLL_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// MYDLL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#include"Interface.h"
#ifdef MYDLL_EXPORTS
#define MYDLL_API __declspec(dllexport)
#else
#define MYDLL_API __declspec(dllimport)
#endif

// �����Ǵ� MyDLL.dll ������
class MYDLL_API CMyDLL :public Interface{
public:
	CMyDLL(void);
	int sum(int a,int b) override;
	// TODO:  �ڴ�������ķ�����
	int m;
	int n;

};

extern MYDLL_API int nMyDLL;

MYDLL_API int fnMyDLL(void);
MYDLL_API Interface *CreateDll()
{
	return new CMyDLL();
}