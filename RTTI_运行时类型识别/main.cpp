#include <typeinfo>
#include <iostream>
using namespace std;
class B
{
public:
	virtual double fun()
	{
		return 0.1;
	}
};
class D :public B
{
};
int main()
{
	B *p = new D;
	B &r = *p;    //�������������б���
	cout << (typeid(p) == typeid(B*)); //��ָ�������и��ಿ��
	cout << (typeid(p) != typeid(D*));  //����ָ�������������
	cout << (typeid(r) == typeid(D));   //���õ�����ȴ�������
	cout << (typeid(*p) == typeid(D)); //��ַ���ʵ����������
	cout << (typeid(*p) != typeid(B));  //���Ǹ���
	cout << (typeid(&r) == typeid(B*)); //���õĵ�ַ�Ǹ����
	cout << (typeid(&r) != typeid(D*));  //���������


	printf("\n%s",typeid(p).name());

	system("pause");

	return 0;
}