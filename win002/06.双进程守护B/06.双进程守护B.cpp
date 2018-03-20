// 06.双进程守护B.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>

int main()
{
	HANDLE hEventB = CreateEvent(NULL, FALSE, TRUE, L"我是B");
	HANDLE hEventA = NULL;
	printf("我是B\n");
	while (true)
	{
		hEventA = OpenEvent(SYNCHRONIZE, NULL, L"我是A");
		if (!hEventA)
		{
			STARTUPINFO si = {};
			PROCESS_INFORMATION pi = {};
			if (!CreateProcess(L"..\\Debug\\05.双进程守护A.exe",
				NULL, NULL, NULL, NULL, CREATE_NEW_CONSOLE, NULL,
				NULL, &si, &pi))
				return 0;
			WaitForSingleObject(pi.hProcess, INFINITE);
			//Sleep(100);
		}
		else
		{
			CloseHandle(hEventA);
		}
	}
	return 0;
}

