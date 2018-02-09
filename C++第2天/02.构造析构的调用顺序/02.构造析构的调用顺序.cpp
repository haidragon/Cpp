// 02.构造析构的调用顺序.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class CClsA {
public:
	CClsA() {
		printf("A\n");
	}
	~CClsA() {
		printf("~A\n");
	}
};
class CClsB {
public:
	CClsB() {
		printf("B\n");
	}
	~CClsB() {
		printf("~B\n");
	}
};
class CClsC {
public:
	CClsC() {
		printf("C\n");
	}
	~CClsC() {
		printf("~C\n");
		//m_objB.~CClsB();
		//m_objA.~CClsA();
	}
	CClsB m_objB;
	CClsA m_objA;
	char * m_p;
};

int main()
{
	CClsC obj;
    return 0;
}

