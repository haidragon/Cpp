// 01.构造函数.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class CMyClsA {
public:
	CMyClsA() {
		m_cA = 'a';
		m_nNumA = 10;
		m_p = new char[10]{};
	}
	~CMyClsA() {
		if (m_p) {
			delete[] m_p;
			m_p = nullptr;
		}
	}
	int m_nNumA;
	char m_cA;
	char *m_p;
};

CMyClsA g_objA;

int FunA(int a) {
	return a;
}



int main() {
	CMyClsA obj;
	// 调用一次
	CMyClsA *p = new CMyClsA;
	// 数组调用构造函数的次数和数组元素个数一致
	CMyClsA arrObj[10];
	return 0;
}

int g_nNumC = FunA(20);