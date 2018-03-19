// 06.遍历模块.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
#include <TlHelp32.h>
bool EnumModule(DWORD dwPID) {
	// 1. 先创建快照
	HANDLE hTool32 = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, dwPID);
	if (INVALID_HANDLE_VALUE == hTool32)
	{
		printf("快照error!\n");
		return false;
	}
	// 2. 开始遍历进程
	MODULEENTRY32W mi = { sizeof(MODULEENTRY32W) };
	BOOL bRet = Module32First(hTool32, &mi);
	if (!bRet)
	{
		printf("Module32First error!\n");
		return false;
	}
	printf("baseaddr    size       handle     name:\n");
	do
	{
		printf("%08x   %08x    %08x   %S\n", 
			(DWORD)mi.modBaseAddr,
			mi.modBaseSize,
			mi.hModule,
			mi.szModule);
	} while (Module32NextW(hTool32, &mi));
	return true;
}

bool EnumProcess() {
	// 1. 先创建快照
	HANDLE hTool32 = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	if (INVALID_HANDLE_VALUE == hTool32)
	{
		printf("快照error!\n");
		return false;
	}
	// 2. 开始遍历进程
	PROCESSENTRY32W psi = { sizeof(PROCESSENTRY32W) };
	BOOL bRet = Process32FirstW(hTool32, &psi);
	if (!bRet)
	{
		printf("Process32FirstW error!\n");
		return false;
	}
	printf("PID    EXE:\n");
	do
	{
		//printf("%4d   %S\n", psi.th32ProcessID, psi.szExeFile);
		EnumModule(psi.th32ProcessID);
	} while (Process32NextW(hTool32, &psi));
	return true;
}


int main()
{
	EnumProcess();
	return 0;
}

