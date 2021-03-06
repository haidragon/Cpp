// 09.菱形继承.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

// 多继承的二义性
class CBase {
public:
	CBase() {
		m_nNumA = 10;
	}
	int m_nNumA;
};

class CBase1:virtual public CBase {
public:
	CBase1() {
		printf("CBase1\n");
	}
};
class CBase2 :virtual public CBase{
public:
	CBase2() {
		printf("CBase2\n");
	}
};
class CDerived :virtual public CBase1, virtual public CBase2 {
public:
	CDerived() {
		printf("CDerived\n");
	}
};

int main()
{
	printf("sizeof(CDerived) = %d\n", sizeof(CDerived));
	CBase1 objBase1;
	CDerived obj;
	obj.m_nNumA;
	obj.CBase1::m_nNumA;
	obj.CBase2::m_nNumA;
	obj.CBase::m_nNumA;

    return 0;
}

