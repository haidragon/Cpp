// C++Day001.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#define HAHAHA "我是这个世界上最可爱的人大大A"+1234342
int main()
{
#define  NUM 100
	printf("%d", NUM);//	printf("%d", 100);
#undef  NUM
	 // error
	printf(HAHAHA);
	// 1.const在数组中的使用
	const int b = 12;
	// C:error C++ right
	int arr[b] = {};
	// 2. const本身的使用
	// 必须初始化
	const int a = 10;
	// 初始化后不能被重新赋值
	//a = 20;
	*(int*)&a = 20;
	printf("%d", a);
	// 和下面相同
	printf("%d", 10);
	int nNumb = a;
	// 和下面的相同
	int nNumC = 10;
	int c = *(int*)&a;
	printf("c = %d", c);
	// 3. 修饰指针的时候
	int nNumA = 100;
	// *p1不允许被赋值
	const int *p1;
	p1 = &nNumA;
	// *p1是const 不能被赋值
	//*p1 = 100;
	nNumA = 200;
	int cnNum = 100;
	// p2不允许被赋值
	int * const p2 = &cnNum;
	
    return 0;
}

