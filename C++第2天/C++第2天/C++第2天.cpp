// C++第2天.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class MyClsA {
public:
	char m_c;
	int m_nA;
	char m_d;
	// 类内定义
	void Fun() {
		// this：调用当前函数的对象的地址
		printf("%d", this->m_d);
	}
	// 声明类里，实现类外
	void Fun2();
protected:
	int m_nE;
private:
};

void MyClsA::Fun2() {
	printf("%d",m_nE);
}

int g_nNumA;

//void Fun(MyClsA obj) {
//	printf("%d", obj.m_nE);
//}

MyClsA objA;

int main()
{
	objA.m_nA = 100;
	objA.Fun();
	MyClsA obj;
	obj.m_nA = 200;
	obj.Fun();

	MyClsA arrObj[5];
	obj.Fun();
	obj.Fun2();
	int g_nNumA;
	int a = ::g_nNumA;
	MyClsA *p = new MyClsA;
	delete p;
    return 0;
}

