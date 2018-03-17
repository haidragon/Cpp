// 03.变参函数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdarg.h>
// %d%s %d%s 。。。
void Fun(int nCount, ...) {
	va_list va;
	va_start(va, nCount);
	// 循环读取变参参数
	for (int i=0;i<nCount;i++)
	{
		// 取int数
		int n = va_arg(va, int);
		char *p = va_arg(va, char*);
		printf("%d%s\n", n, p);
	}
	va_end(va);
}
int main()
{
	Fun(3, 12, "12", 34, "34", 56, "12345");
	Fun(2, 88,"34", 56, "12345");
    return 0;
}

