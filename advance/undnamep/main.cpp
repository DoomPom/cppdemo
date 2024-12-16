#include <Windows.h>
#include<iostream>

using namespace std;

/*

buffer	[Out]	If not NULL, the place to put the demangled string.
mangled	[In]	Mangled name of the function.
buflen	[In]	Length of buffer.
memget	[In]	Function to allocate memory with.
memfree	[In]	Function to free memory with.
unknown	[?]	Unknown, possibly a call back
flags	[In]	Flags determining demangled format.
*/
union TU{
	char bit;
	double db;
	long long ll;
	float f;
	int t;
};
class A
{
public:
	static void s1() { printf("%s\n", __FUNCDNAME__); s2(2); };
private:
	static void s2(int a) { printf("%s\n", __FUNCDNAME__); };
public:
	int age;
	void a() { printf("%s\n", __FUNCDNAME__); b(2); c(NULL); };
	void e(char d) { printf("%s\n", __FUNCDNAME__);  };
	int f() { printf("%s\n", __FUNCDNAME__); return 0; };
private:
	int b(int d) { printf("%s\n", __FUNCDNAME__); return d; };
protected:
	bool c(void* buf) { printf("%s\n", __FUNCDNAME__); return buf == NULL; };
};
class B
{
public:
	B() {
		TU t;
		t.ll = 20l;
		a();	// ?a@B@@QAEXXZ
		b(1);	// ?b@B@@QAEXH@Z
		c(2);	// ?c@B@@QAEXI@Z
		d(NULL);// ?d@B@@QAEXPAX@Z
		e(NULL);// ?e@B@@QAEXPAD@Z
		f(NULL);// ?f@B@@QAEXP6AXPAD@Z@Z
		g(NULL);// ?g@B@@QAEXPAPAH@Z
		h(NULL);// ?h@B@@QAEXQAPAH@Z
		i(t,2);	// ?i@B@@QAEXTTU@@@Z
		j(NULL);// ?j@B@@QAEXPAVA@@@Z
	}	
	void a() { printf("%s\n", __FUNCDNAME__);};
	void b(int c) { printf("%s\n", __FUNCDNAME__); };
	void c(unsigned int i) { printf("%s\n", __FUNCDNAME__); };
	void d(void* ptr) { printf("%s\n", __FUNCDNAME__); };
	void e(char* ptr) { printf("%s\n", __FUNCDNAME__); };
	void f(void (*fun)(char*)) { printf("%s\n", __FUNCDNAME__); };
	void g(const int** const ptr) { printf("%s\n", __FUNCDNAME__); };
	void h(int* ptr[]) { printf("%s\n", __FUNCDNAME__); };
	void i(TU u,int a) { printf("%s\n", __FUNCDNAME__); };
	void j(A* a) { printf("%s\n", __FUNCDNAME__); };
};
class C
{
public:
	C() {
		printf("%s\n", __FUNCDNAME__);  // ??0C@@QAE@XZ
		a();// ?a@C@@QAEXXZ
		b();// ?b@C@@IAEXXZ
		c();// ?c@C@@AAEXXZ
		d();// ?d@C@@SAXXZ
		e();// ?e@C@@KAXXZ
		f();// ?f@C@@CAXXZ
		g();// ?g@C@@UAEXXZ
		h();// ?h@C@@MAEXXZ
		i();// ?i@C@@EAEXXZ
		j();// ?j@C@@QAGXXZ
		k();// ?k@C@@QAAXXZ
		l();// ?l@C@@QAIXXZ
		//m();
		m();
		n();
		o();
	}
	~C() {printf("%s\n", __FUNCDNAME__);  }

public:				void a() { printf("%s\n", __FUNCDNAME__); };
protected:			void b() { printf("%s\n", __FUNCDNAME__); };
private:			void c() { printf("%s\n", __FUNCDNAME__); };
public:		static	void d() { printf("%s\n", __FUNCDNAME__); };
protected:	static	void e() { printf("%s\n", __FUNCDNAME__); };
private:	static	void f() { printf("%s\n", __FUNCDNAME__); };
public:		virtual void g() { printf("%s\n", __FUNCDNAME__); };
protected:	virtual void h() { printf("%s\n", __FUNCDNAME__); };
private:	virtual void i() { printf("%s\n", __FUNCDNAME__); };
public:	 void __stdcall j() { printf("%s\n", __FUNCDNAME__); };
public:	 void __cdecl k() { printf("%s\n", __FUNCDNAME__); };
public:	 void __fastcall l() { printf("%s\n", __FUNCDNAME__); };
public:	static  void __stdcall m() { printf("%s\n", __FUNCDNAME__); };
public:	static  void __cdecl n() { printf("%s\n", __FUNCDNAME__); };
public:	static  void __fastcall o() { printf("%s\n", __FUNCDNAME__); };

//public:	  __declspec(naked) void m() { printf("%s\n", __FUNCDNAME__); };  // �������ڷǳ�Ա����
//public:	 void __pascal m() { printf("%s\n", __FUNCDNAME__); }; // �ѷ�����֧�֣�����ֱ��ʹ��
};

int main(int argc, char* argv[])
{
	//cout << "Hello World !" << endl;
	//A* a = new A();
	C* obj = new C();
	delete obj;
	
	return 0;
}


/*
* 
undname ?a@A@@QAEXXZ
�������������� ?__funcname__@__classname__@@__funcsig__
__FUNCTION__ :a
__FUNCDNAME__ : ?a@A@@QAEXXZ
__FUNCSIG__ : public: void __thiscall A::a(void)
����: Ȩ�� ���� ����Լ�� ����ֵ ������ �������� ��������
X void
H int
D char

Hello World !

?b@A@@AAEHH@Z
?c@A@@IAE_NPAX@Z
?e@A@@QAEXL@Z

?a@A@@QAEXXZ
?e@A@@QAEXH@Z
?e@A@@QAEXD@Z
?f@A@@QAEHXZ
?f@A@@QAEHXZ
?s1@A@@SAXXZ
?s2@A@@CAXH@Z
?p@@YAXHDPAX@Z
?e@A@@QAEXH@Z
?j@B@@QAEXPAVA@@@Z

@Z/Z Z�ǽ�����ʶ�� @��ʾ�в���

X--void 
C-signed char
D--char
E--unsigned char
F--short
G--unsigned short
H--int
I--unsigned int
J--long
K--unsigned long
M--float
N--double
O--long double
_N--bool
PAt--ָ�룬t* 
PBt--ָ�룬t const* 
PCt--ָ�룬t volatile* 
PDt--ָ�룬t const volatile*
QAt--ָ�� t* const
RAt--ָ�� t* volatile
SAt--ָ�� t* const volatile
T --union   TTU@@H@Z => (union TU,int ) ; T TU @@ = union ������ @@(����)
U --stuct  ?j@B@@QAEXPAVA@@@Z
V --class
Y -- ȫ�ֺ���
����ָ��---> 
?f@B@@QAEXP6AHH@Z@Z  ==> public: void __thiscall B::f(int (__cdecl*)(int))
==> P6AHH@Z@Z==> P6(����ָ��) A( _cdecl_ ����Լ��) H(����ֵ) H(���������б�) @Z(��������) @Z
undname ?f@B@@QAEXP6APAHH@Z@Z
P6A => P6(����ָ������) A(����Լ��)
����Լ��:
__cdecl cb ��Ĭ��ֵ�����������������ǰ�� "_"���������˺��������䣬�������մ��ҵ����˳�����δ��ݸ�ջ��Ҳ����д��_cdecl��cdecl��ʽ��
__fastcall ���εĺ����Ĳ����������ܵ�ʹ�üĴ����������亯����ǰ��@���������մ����ҵ�˳��ѹջ��
__pascal ��˵���ĺ�����ʹ�� Pascal ��ʽ������Լ������ʱ������ȫ����д���������մ����ҵ�˳��ѹջ��
__stdcall ʹ�ñ�׼Լ���ĺ�����������������ı䡣ʹ�� __stdcall ����ʱ�������������ҵ����˳��ѹջ��Ҳ������_stdcall

-- �޷���ֵ�� ����ֵλʹ�� @ ռ��
���캯��  ??0C@@QAE@XZ	 public: __thiscall C::C(void)
��������  ??1C@@QAE@XZ	 public: __thiscall C::~C(void)

���δ�: 
undname ?a@C@@QAEXXZ	public: void __thiscall C::a(void)
undname ?b@C@@IAEXXZ	protected: void __thiscall C::b(void)
undname ?c@C@@AAEXXZ	private: void __thiscall C::c(void)
undname ?d@C@@SAXXZ		public: static void __cdecl C::d(void)
undname ?e@C@@KAXXZ		protected: static void __cdecl C::e(void)
undname ?f@C@@CAXXZ		private: static void __cdecl C::f(void)
undname ?g@C@@UAEXXZ	public: virtual void __thiscall C::g(void)
undname ?h@C@@MAEXXZ	protected: virtual void __thiscall C::h(void)
undname ?i@C@@EAEXXZ	private: virtual void __thiscall C::i(void)
undname ?j@C@@QAGXXZ	public: void __stdcall C::j(void)
undname ?k@C@@QAAXXZ	public: void __cdecl C::k(void)
undname ?l@C@@QAIXXZ	public: void __fastcall C::l(void)
undname ?m@C@@SGXXZ		public: static void __stdcall C::j(void)
undname ?n@C@@SAXXZ		public: static void __cdecl C::k(void)
undname ?o@C@@SIXXZ		public: static void __fastcall C::l(void)
��һλ:
A -- private
C -- private static
E -- private virtual
K -- protected  static
I -- protected
M -- protected virtual
Q -- public 
S -- public static
U -- public virtual

�ڶ�λ:
A -- ��ַ
B -- ��ַ const
C -- ��ַ volatile
D -- ��ַ const volatile

����λ:
E -- __thiscall
A -- __cdecl
G -- __stdcall
I -- __fastcall

��̬�ڶ�λ: static û�е���λ.
A -- __cdecl
G -- __stdcall
I -- __fastcall
*/