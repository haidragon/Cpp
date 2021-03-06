// 07.类型转换.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	// C的强制转换
	int a =10;
	int *p = &a;
	int nAddr = (int)p;
	// C的隐式类型转换
	int nNumA = 'a';
	// C++
	//const_cast<>;
	//reinterpret_cast<>;
	//static_cast<>;
	//dynamic_cast<>;

	// 转换方式<转换后的类型>(被转换的值)
	// 1. const_cast<> 去常量类型转换
	const int nNumB = 10;
	int &nNumC = const_cast<int&>(nNumB);
	// 对应C的强制类型转换
	int &nNumD = (int&)nNumB;
	// 2. reinterpret_cast<>
	int nNumE = 10;
	int nAddrE = reinterpret_cast<int>(&nNumE);
	// 对应于C的强制类型转换
	int nAddrF = (int)&nNumE;
	// 3. static_cast<> 对应于C的隐式类型转换
	int nNumF = static_cast<int>('a');

    return 0;
}

