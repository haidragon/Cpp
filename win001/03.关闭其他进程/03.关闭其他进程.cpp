// 03.关闭其他进程.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <windows.h>

bool KillProcess(DWORD dwPid) {
	// 打开进程
	HANDLE hProcess = OpenProcess(PROCESS_TERMINATE,NULL,dwPid);
	if (!hProcess)
	{
		return false;
	}
	TerminateProcess(hProcess, 0);
	CloseHandle(hProcess);
	return true;
}

int main()
{
	KillProcess(4484);
	//exit(0);
    return 0;
}

