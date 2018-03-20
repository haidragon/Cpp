// 08.异步IO-等待文件对象.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
typedef struct _MYOVERLAPPED{
	OVERLAPPED ol;
	HANDLE hFile;
	PBYTE pBuf;
	int nIndex;
}MYOVERLAPPED,*PMYOVERLAPPED;

DWORD WINAPI ThreadProc(LPVOID lParam) {
	PMYOVERLAPPED pol = (PMYOVERLAPPED)lParam;
	WaitForSingleObject(pol->hFile, INFINITE);
	for (int i=0;i<10;i++)
	{
		printf("%d:%02x \n", pol->nIndex,pol->pBuf[i]);
	}
	printf("读完了！\n");
	return 0;
}

int main()
{
	// 1. 异步IO标记
	// 有了这个标记 该文件就变为可等待的内核对象
	// 后面的read write函数就变为非阻塞的
	HANDLE hFile = CreateFile(L"..\\Debug\\123.exe", GENERIC_READ,
		FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL| FILE_FLAG_OVERLAPPED, NULL);
	// 2. 文件读取
	PMYOVERLAPPED pol = new MYOVERLAPPED{};
	pol->ol.Offset = 0x100;// 从偏移0x100这个位置开始读
	// pol->hEvent == NULL; 系统读取完成后，会把我的hFile变为有信号状态
	pol->hFile = hFile;
	pol->pBuf = new BYTE[0x1000]{};
	pol->nIndex =1;
	ReadFile(hFile,
		pol->pBuf,
		0x1000,
		NULL,//实际读取的个数，由OVERLAPPED结构体指定
		(LPOVERLAPPED)pol);
	HANDLE hThread = CreateThread(NULL, NULL, ThreadProc, pol, NULL, NULL);
	
	
	PMYOVERLAPPED pol2 = new MYOVERLAPPED{};
	pol2->ol.Offset = 0x200;// 从偏移0x100这个位置开始读
						   // pol->hEvent == NULL; 系统读取完成后，会把我的hFile变为有信号状态
	pol2->hFile = hFile;
	pol2->pBuf = new BYTE[0x1000]{};
	pol2->nIndex = 2;
	ReadFile(hFile,
		pol2->pBuf,
		0x1000,
		NULL,//实际读取的个数，由OVERLAPPED结构体指定
		(LPOVERLAPPED)pol2);
	HANDLE hThread2 = CreateThread(NULL, NULL, ThreadProc, pol2, NULL, NULL);

	
	
	// ......干其他事
	WaitForSingleObject(hThread, INFINITE);
	WaitForSingleObject(hThread2, INFINITE);
    return 0;
}

