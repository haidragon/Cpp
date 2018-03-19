// 07.伪句柄转真正句柄.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>

DWORD WINAPI ChildThread(PVOID pParam) {
	HANDLE hThreadParent = (HANDLE)pParam;
	FILETIME stcCreationTime, stcExitTime;
	FILETIME stcKernelTime, stcUserTime;
	GetThreadTimes(hThreadParent, &stcCreationTime,
		&stcExitTime, &stcKernelTime, &stcUserTime);
	return 0;
}

DWORD WINAPI ShowParentTime() {
	HANDLE hThreadParent = GetCurrentThread();
	// 把伪句柄转换成真正的句柄值
	HANDLE hTranslate = 0;
	DuplicateHandle(
		GetCurrentProcess(),//你要转换的句柄值所在的进程句柄
		hThreadParent,// 你要转换哪个句柄
		GetCurrentProcess(),// 你要转换的句柄给哪个进程
		&hTranslate,
		DUPLICATE_SAME_ACCESS,// 一样的权限
		NULL,
		DUPLICATE_SAME_ACCESS);
	CreateThread(NULL, 0, ChildThread,
		(PVOID)hTranslate, 0, NULL);
	return 0;
}

int main()
{
	FILETIME stcCreationTime, stcExitTime;
	FILETIME stcKernelTime, stcUserTime;
	GetThreadTimes(GetCurrentThread(), &stcCreationTime,
		&stcExitTime, &stcKernelTime, &stcUserTime);
	ShowParentTime();
	system("pause");
    return 0;
}

