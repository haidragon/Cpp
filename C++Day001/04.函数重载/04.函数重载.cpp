// 04.函数重载.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

char Fun(int a) {
	printf("%d\n", a);
}

//int Fun(int a) {
//	printf("%d\n", a);
//}

void Fun(char b) {
	printf("%c\n", b);
}

int main()
{
	Fun(10);
	Fun('a');
    return 0;
}

