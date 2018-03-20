// 03.防多开.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>

int main()
{
	if (OpenMutex(SYNCHRONIZE, NULL, L"24期"))
	{
		// 说明互斥体存在，已经打开过一次程序
		return 0;
	}
	HANDLE hMutex = CreateMutex(NULL, NULL, L"24期");
	system("pause");
    return 0;
}

