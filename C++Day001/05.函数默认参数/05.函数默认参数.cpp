// 05.函数默认参数.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

void Fun(int a, int b);
void Fun(int a = 10,int b=20) {
	printf("%d", a);
}

void Fun1(int a = 10);
void Fun1(int a) {
	printf("%d",a);
}

// error!
void Fun2(int a = 10);
void Fun2(int a = 10) {
	printf("%d", a);
}

void Fun() {
	printf("void\n");
}
int main()
{
	Fun(10,20);
	// Fun();
	//Fun();
    return 0;
}

