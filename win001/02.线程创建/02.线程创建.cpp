// 02.线程创建.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
int g_nNum = 0;

DWORD WINAPI ThreadProc(LPVOID lParam) {
	printf("我是线程！\n");
	for (int i=0;i<100000;i++)
	{
		g_nNum++;
	}
	printf("%d\n", g_nNum);
	return 0;
}

int main()
{

	CreateThread(NULL, NULL, ThreadProc, NULL, 0, NULL);
	CreateThread(NULL, NULL, ThreadProc, NULL, 0, NULL);

	system("pause");
	printf("%d\n", g_nNum);
    return 0;
}

