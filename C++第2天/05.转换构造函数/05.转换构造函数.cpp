// 05.转换构造函数.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class CMyClsA {
public:
	CMyClsA(const int a) {
		m_nNumA = a;
	}
	CMyClsA(char c) {
		m_C = c;
	}
	void Fun()const {
	}
	int m_nNumA;
	char m_C;
};

int main()
{
	CMyClsA objA = 10;//CMyClsA objA(10);
	int a = 10;
	int b(10);
	//b(20); b = 20;
	//CMyClsA objB = 'a';
	&objA;
	//objB = (CMyClsA)20;
    return 0;
}

