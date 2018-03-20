// 08.异步IO-异步过程调用(APC).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
typedef struct _MYOVERLAPPED {
	OVERLAPPED ol;
	HANDLE hFile;
	PBYTE pBuf;
	int nIndex;
}MYOVERLAPPED, *PMYOVERLAPPED;


// 提交任务的线程处理，其他线程看着
VOID CALLBACK FileIOCompletionRoutine(
	_In_    DWORD        dwErrorCode,
	_In_    DWORD        dwNumberOfBytesTransfered,
	_Inout_ LPOVERLAPPED lpOverlapped
) {
	PMYOVERLAPPED pol = (PMYOVERLAPPED)lpOverlapped;
	for (int i = 0; i < 10; i++)
	{
		printf("%d:%02x \n", pol->nIndex, pol->pBuf[i]);
	}
	printf("读完了！\n");
}


int main()
{
	// 1. 异步IO标记
	// 有了这个标记 该文件就变为可等待的内核对象
	// 后面的read write函数就变为非阻塞的
	HANDLE hFile = CreateFile(L"..\\Debug\\123.exe", GENERIC_READ,
		FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, NULL);
	// 2. 文件读取
	PMYOVERLAPPED pol = new MYOVERLAPPED{};
	pol->ol.Offset = 0x100;// 从偏移0x100这个位置开始读
	// hEvent被无视   hFile也被无视
	//pol->ol.hEvent = CreateEvent(NULL, NULL, FALSE, NULL); //系统读取完成后，会把我的hFile变为有信号状态
	pol->hFile = hFile;// 被无视
	pol->pBuf = new BYTE[0x1000]{};
	pol->nIndex = 1;
	ReadFileEx(hFile,
		pol->pBuf,
		0x1000,
		(LPOVERLAPPED)pol,
		FileIOCompletionRoutine);// 完成后直接调用该回调函数，不用等待文件句柄/事件对象

	PMYOVERLAPPED pol2 = new MYOVERLAPPED{};
	pol2->ol.Offset = 0x200;// 从偏移0x100这个位置开始读
	//pol2->ol.hEvent = CreateEvent(NULL, NULL, FALSE, NULL); //系统读取完成后，会把我的hFile变为有信号状态
	//pol2->hFile = hFile;// 被无视
	pol2->pBuf = new BYTE[0x1000]{};
	pol2->nIndex = 2;
	ReadFileEx(hFile,
		pol2->pBuf,
		0x1000,
		(LPOVERLAPPED)pol2,
		FileIOCompletionRoutine);
	// FileIOCompletionRoutine有系统调用
	// 哪个线程执行该函数呢
	// 哪个线程read/write 哪个线程执行
	// ......干其他事

	// 忙完了  想起来还有两个函数等着我呢
	// CPU检测到当前线程的APC队列里有函数需要执行
	// 就去执行该函数，执行完返回
	// 只有当第2个参数是TRUE才去执行
	SleepEx(200, TRUE);
//	WaitForSingleObjectEx()
	return 0;
}
