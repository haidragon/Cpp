// 03.带参构造和初始化列表.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class CTest {
public:
	CTest(int a) {
		m_a = a;
	}
	CTest() {
		m_a = 10;
	}
	int m_a;
};


class CMyCls {
public:
	CMyCls(int a)
	:m_nNumB(a),m_obj(a)
	{
		//m_obj(10);// m_obj(10)->函数名为m_obj参数为10的函数调用
		m_nNumA = a;
		m_cA = 'a';
	}
	CTest m_obj;
	int m_nNumA;
	char m_cA;
	const int m_nNumB = 10;
};

int main()
{
	const int a = 10;
	//a = 100;
	int b = 10;
	b = 100;
	int &c = b;
	c = 20;
    return 0;
}

