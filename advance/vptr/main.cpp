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
* 方法绑定: 
	静态绑定。跟着类型走
	动态绑定, 创建的的时候绑定。
1. virtual 编译的时候会添加一个 void** __vfptr; 的成员变量。
2. 子类编译的时候，先 父的成员变量，然后填充自己的成员变量，若存在 __vfptr，则查找字类的方法，有重载则替换。

1. 创建字类对象的，父类指针指向字类，因为使用的是子类的 __vfptr
2. 调用的方法，首先是找 __vfptr ，不存在再 查找调用类的方法。

调用的时候方法寻找: 
1. 
*/