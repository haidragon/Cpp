// 04.事件对象.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
HANDLE hEvent1, hEvent2;
DWORD WINAPI ThreadProcA(LPVOID lParam) {
	for (int i = 0; i < 10; i++){
		WaitForSingleObject(hEvent1, INFINITE);
		printf("A ");
		SetEvent(hEvent2);
	}
	return 0;
}

DWORD WINAPI ThreadProcB(LPVOID lParam) {
	for (int i = 0; i < 10; i++){
		WaitForSingleObject(hEvent2, INFINITE);
		printf("B ");
		SetEvent(hEvent1);
	}
	return 0;
}

int main()
{
	// 事件对象，高度自定义的
	 hEvent1 = CreateEvent(
		NULL,
		FALSE,// 自动重置
		TRUE,// 有信号
		NULL);
	// hEvent1自动重置  初始有信号  任何人通过setevent变为有信号 resetevent变为无信号
	// hEvent2自动重置  初始无信号
	 hEvent2 = CreateEvent(NULL, FALSE, FALSE, NULL);
	HANDLE hThread1 = CreateThread(NULL, NULL, ThreadProcA, NULL, NULL, NULL);
	HANDLE hThread2 = CreateThread(NULL, NULL, ThreadProcB, NULL, NULL, NULL);
	WaitForSingleObject(hThread1, INFINITE);
	WaitForSingleObject(hThread2, INFINITE);
	return 0;
}

