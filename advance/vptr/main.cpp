#include<iostream>

using namespace std;

class A
{
public:
	int age;
	void a() { printf("%s\n", __FUNCDNAME__); };
	virtual void b() { printf("%s\n", __FUNCDNAME__); };
	virtual void c() { printf("%s\n", __FUNCDNAME__); };
};
class B:public A
{
public :
	B() { id = 0x1234, age = 0x5678; };
	int id;
	void a() { printf("%s\n", __FUNCDNAME__); };
	void b() { printf("%s\n", __FUNCDNAME__); };
	//void c() { printf("%s\n", __FUNCDNAME__); };
};

int main(int argc, char* argv[])
{
	printf("size: %d,%d\n", sizeof(A),sizeof(B));
	B b;
	A* a = &b;
	a->a(); // A
	a->b(); // B
	a->c(); // B
	return 0;
}
/*
* ������: 
	��̬�󶨡�����������
	��̬��, �����ĵ�ʱ��󶨡�
1. virtual �����ʱ������һ�� void** __vfptr; �ĳ�Ա������
2. ��������ʱ���� ���ĳ�Ա������Ȼ������Լ��ĳ�Ա������������ __vfptr�����������ķ��������������滻��

1. �����������ģ�����ָ��ָ�����࣬��Ϊʹ�õ�������� __vfptr
2. ���õķ������������� __vfptr ���������� ���ҵ�����ķ�����

���õ�ʱ�򷽷�Ѱ��: 
1. 
*/