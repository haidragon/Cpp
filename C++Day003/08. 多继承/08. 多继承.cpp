// 08. 多继承.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

// 多继承的二义性
class CBase1 {
public:
	CBase1() {
		printf("CBase1\n");
	}
	int m_nNumA;
	int m_nNumA1;
};
class CBase2 {
public:
	CBase2() {
		printf("CBase2\n");
	}
	int m_nNumA;
	int m_nNumA2;
};
class CDerived :public CBase1,public CBase2{
public:
	CDerived() {
		printf("CDerived\n");
	}
};
int main()
{
	CDerived obj;
	obj.m_nNumA1;
	obj.m_nNumA2;
	obj.CBase1::m_nNumA;
    return 0;
}

