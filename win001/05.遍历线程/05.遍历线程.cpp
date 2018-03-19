// 05.遍历线程.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
#include <TlHelp32.h>
bool EnumThreads(DWORD dwPID) {
	// 1. 先创建快照
	HANDLE hTool32 = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, NULL);
	if (INVALID_HANDLE_VALUE == hTool32)
	{
		printf("快照error!\n");
		return false;
	}
	// 2. 开始遍历进程
	THREADENTRY32 ti = { sizeof(THREADENTRY32) };
	BOOL bRet = Thread32First(hTool32, &ti);
	if (!bRet)
	{
		printf("Thread32First error!\n");
		return false;
	}
	printf("tID    pid:\n");
	do
	{
		if (ti.th32OwnerProcessID == dwPID)
		{
			printf("%6d   %6d\n", ti.th32ThreadID, ti.th32OwnerProcessID);
		}
	} while (Thread32Next(hTool32, &ti));
	return true;
}

int main()
{
	EnumThreads(7568);
	return 0;
}


