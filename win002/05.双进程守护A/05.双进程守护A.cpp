// 05.双进程守护A.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>

int main()
{
	HANDLE hEventA = CreateEvent(NULL, FALSE, TRUE, L"我是A");
	HANDLE hEventB = NULL;
	printf("我是A\n");
	while (true)
	{
		hEventB = OpenEvent(SYNCHRONIZE, NULL, L"我是B");
		if (!hEventB)
		{
			STARTUPINFO si = {};
			PROCESS_INFORMATION pi = {};
			if (!CreateProcess(L"..\\Debug\\06.双进程守护B.exe",
				NULL, NULL, NULL, NULL, CREATE_NEW_CONSOLE, NULL,
				NULL, &si, &pi))
				return 0;
			WaitForSingleObject(pi.hProcess, INFINITE);
			Sleep(100);
		}
		else
		{
			CloseHandle(hEventB);
			Sleep(200);
		}
	}
	return 0;
}

