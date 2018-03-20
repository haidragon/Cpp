// 07.信号量.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <windows.h>
HANDLE hSemphore;
int g_nNum = 0;
DWORD WINAPI ThreadProc(LPVOID lParam) {
		WaitForSingleObject(hSemphore, INFINITE);
	for (int i = 0; i < 100000; i++)
	{
		g_nNum++;
	}
	printf("%d\n", g_nNum);
	ReleaseSemaphore(hSemphore,
		1,// 释放的信号个数可以大于1，但是释放后的信号个数+之前的不能大于最大值，否则释放失败
		NULL);
	return 0;
}

int main()
{
	 hSemphore = CreateSemaphore(
		NULL,
		1,// 初始信号个数
		1,// 最大信号个数，就是允许同时访问保护资源的线程数
		NULL);
	HANDLE hThread1 = CreateThread(NULL, NULL, ThreadProc, NULL, NULL, NULL);
	HANDLE hThread2 = CreateThread(NULL, NULL, ThreadProc, NULL, NULL, NULL);
	WaitForSingleObject(hThread1, INFINITE);
	WaitForSingleObject(hThread2, INFINITE);
	printf("%d\n", g_nNum);
	return 0;
}


