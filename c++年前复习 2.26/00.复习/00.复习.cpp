// 00.复习.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "标头.h"
#include <iostream>
#include <iomanip>
using namespace std;
using std::cin;
namespace XXX {
	int a;
}
class A {
public:
	int m_nNum;
};
class B :protected A{
public:
	A::m_nNum;// 保护变公有
};
class C {
public:
	C() { printf("C\n"); }
	B m_b;
	A m_a;
};

class D {
public:
	explicit D(int a) {
		m_nNum = a;
	}
	int m_nNum;
};
int main() {
	D obj(10);
	D objA = D(20);
	objA = D(100);
	return 0;
}

