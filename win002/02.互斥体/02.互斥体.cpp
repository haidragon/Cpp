// win002.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
HANDLE hMutex = 0;
int g_nNum = 0;
// 临界区和互斥体比较
// 1. 互斥体是个内核对象，可以跨进程同步,临界区不行
// 2. 当他们的拥有者线程都崩溃的时候，互斥体可以被系统释放，变为有信号，其他的等待函数可以正常返回
// 临界区不行,如果都是假死(死循环，无响应)，他们都会死锁
// 3. 临界区不是内核对象，所以访问速度比互斥体快
DWORD WINAPI ThreadProc(LPVOID lParam) {
	// 等待某个内核对象，有信号就返回，无信号就一直等待
	// 返回时把等待的对象变为无信号状态
	WaitForSingleObject(hMutex, INFINITE);
	for (int i = 0; i < 100000; i++)
	{
		g_nNum++;
	}
	printf("%d\n", g_nNum);
	// 把互斥体变为有信号状态
	ReleaseMutex(hMutex);
	return 0;
}

int main()
{
	// 1. 创建一个互斥体
	hMutex = CreateMutex(
		NULL,
		FALSE,// 是否创建时就被当先线程拥有
		NULL);// 互斥体名称
	HANDLE hThread1 = CreateThread(NULL, NULL, ThreadProc, NULL, NULL, NULL);
	HANDLE hThread2 = CreateThread(NULL, NULL, ThreadProc, NULL, NULL, NULL);
	WaitForSingleObject(hThread1, INFINITE);
	WaitForSingleObject(hThread2, INFINITE);
	printf("%d\n", g_nNum);
	return 0;
}

