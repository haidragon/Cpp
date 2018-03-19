// win001.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<windows.h>

int main()
{
	STARTUPINFO si = {};
	PROCESS_INFORMATION pi = {};
	BOOL bRet = CreateProcess(
		L"123",
		NULL, NULL, NULL, FALSE, NULL, NULL, NULL,
		&si, &pi
	);
	if (bRet == FALSE)
	{
		printf("启动失败！\n");
	}
    return 0;
}

