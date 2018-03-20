// 08.异步过程调用-完成端口(IOCP).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
typedef struct _MYOVERLAPPED {
	OVERLAPPED ol;
	HANDLE hFile;
	PBYTE pBuf;
	int nIndex;
}MYOVERLAPPED, *PMYOVERLAPPED;

DWORD WINAPI ThreadProc(LPVOID lParam) {
	PMYOVERLAPPED pol =nullptr;
	HANDLE hIOCP = lParam;
	while (TRUE)
	{
		DWORD dwNum = 0;
		ULONG_PTR uCompleteKey = 0;
		BOOL bRet = GetQueuedCompletionStatus(
			hIOCP,// 检查完成端口有没有待处理任务(有任务完成，通知完成端口处理)
			&dwNum,// 实际传输的字节数
			&uCompleteKey,// 哪个设备完成了异步操作
			(LPOVERLAPPED*)&pol,
			INFINITE);
		if (bRet == FALSE && ERROR_ABANDONED_WAIT_0 == GetLastError())
		{
			printf("完成端口被关闭\n");
			return 0;
		}
		if (uCompleteKey == NULL && pol == nullptr)
		{
			PostQueuedCompletionStatus(hIOCP, NULL, NULL, NULL);
			printf("完成端口线程结束!\n");
			return 0;
		}
		for (int i = 0; i < 10; i++)
		{
			
			printf("key:%d,%d:%02x \n", uCompleteKey,pol->nIndex, pol->pBuf[i]);
		}
		printf("读完了！\n");
	}
	return 0;
}

int main()
{
	// 1. 异步IO标记
	// 有了这个标记 该文件就变为可等待的内核对象
	// 后面的read write函数就变为非阻塞的
	HANDLE hFile = CreateFile(L"..\\Debug\\123.exe", GENERIC_READ,
		FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, NULL);
	
	// 2. 创建一个完成端口
	// 先获取核心数
	SYSTEM_INFO si = {};
	GetSystemInfo(&si);
	HANDLE hIOCP = CreateIoCompletionPort(
		INVALID_HANDLE_VALUE,// 创建完成端口,绑定完成端口的时候是文件句柄
		NULL,// 创建完成端口的时候是NULL,绑定的时候是完成端口句柄
		NULL,// 创建完成端口的时候是NULL,绑定的时候是自己设置的一个值，用来区分绑定的文件是哪个
		si.dwNumberOfProcessors);// 完成端口上并行运行的最大线程数，绑定的时候是NULL
	// 3.把完成端口和文件绑定，后面这个文件的所有异步操作的通知都交给完成端口
	CreateIoCompletionPort(
		hFile,
		hIOCP,
		0x12,// 和hFile绑定的值，也可以是hFile本身
		NULL
	);
	// 4. 创建完成端口的服务线程
	for (int i=0;i<si.dwNumberOfProcessors*2;i++)
	{
		CreateThread(NULL, NULL, ThreadProc, hIOCP, NULL, NULL);
	}
	
	// 5. 文件读取
	PMYOVERLAPPED pol = new MYOVERLAPPED{};
	pol->ol.Offset = 0x100;// 从偏移0x100这个位置开始读
	pol->pBuf = new BYTE[0x1000]{};
	pol->nIndex = 1;
	ReadFile(hFile,
		pol->pBuf,
		0x1000,
		NULL,//实际读取的个数，由OVERLAPPED结构体指定
		(LPOVERLAPPED)pol);


	PMYOVERLAPPED pol2 = new MYOVERLAPPED{};
	pol2->ol.Offset = 0x200;// 从偏移0x100这个位置开始读
	pol2->pBuf = new BYTE[0x1000]{};
	pol2->nIndex = 2;
	ReadFile(hFile,
		pol2->pBuf,
		0x1000,
		NULL,//实际读取的个数，由OVERLAPPED结构体指定
		(LPOVERLAPPED)pol2);
	// ......干其他事
	// 投递一个完成任务
	PostQueuedCompletionStatus(hIOCP, NULL, NULL, NULL);
	system("pause");
	return 0;
}


