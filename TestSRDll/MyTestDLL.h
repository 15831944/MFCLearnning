// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� MYTESTDLL_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// MYTESTDLL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef MYTESTDLL_EXPORTS
#define MYTESTDLL_API __declspec(dllexport)
#else
#define MYTESTDLL_API __declspec(dllimport)
#endif

// �����Ǵ� MyTestDLL.dll ������
class MYTESTDLL_API CMyTestDLL {
public:
	CMyTestDLL(int m,int n);
	// TODO:  �ڴ�������ķ�����
	CMyTestDLL(int m);
	 virtual int sum();

private:
	int a;
	int b;
};

extern MYTESTDLL_API int nMyTestDLL;

MYTESTDLL_API int fnMyTestDLL(void);
