// win002.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>

CRITICAL_SECTION cs = {};

int g_nNum = 0;
DWORD WINAPI ThreadProc(LPVOID lParam) {
	// 2. 进入临界区
	// cs有个属性LockSemaphore是不是被锁定
	// 当调用EnterCriticalSection表示临界区被锁定，OwningThread就是该线程
	// 其他调用EnterCriticalSection，会检查和锁定时的线程是否是同一个线程
	// 如果不是，调用Enter的线程就阻塞
	// 如果是，就把锁定计数LockCount+1
	// 有几次Enter就得有几次Leave
	// 但是，不是拥有者线程的人不能主动Leave
	EnterCriticalSection(&cs);
	for (int i = 0; i < 100000; i++)
	{
		g_nNum++;
	}
	printf("%d\n", g_nNum);
	// 3. 离开临界区
	// 万一，还没有调用Leave，该线程就崩溃了，或死循环了..
	// 外面等待的人就永远等待
	// 临界区不是内核对象， 不能跨进程同步
	LeaveCriticalSection(&cs);
	return 0;
}

int main()
{
	// 1. 初始化临界区
	InitializeCriticalSection(&cs);
	HANDLE hThread1 = CreateThread(NULL, NULL, ThreadProc, NULL, NULL, NULL);
	HANDLE hThread2 = CreateThread(NULL, NULL, ThreadProc, NULL, NULL, NULL);
	WaitForSingleObject(hThread1, INFINITE);
	WaitForSingleObject(hThread2, INFINITE);
	printf("%d\n", g_nNum);
	// 4. 销毁临界区
	DeleteCriticalSection(&cs);
	return 0;
}

