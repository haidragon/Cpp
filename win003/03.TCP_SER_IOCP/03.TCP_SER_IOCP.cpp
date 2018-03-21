// 03.TCP_SER_IOCP.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MyTCP.h"
#include <windows.h>
CMyTCP g_tcp;

typedef struct _MYOVERLAPPED
{
	OVERLAPPED ol;
	WSABUF wsa;
	char buf[1024];
}MYOVERLAPPED,*PMYOVERLAPPED;

DWORD WINAPI IOCP_Thread(LPVOID lParam) {
	HANDLE hIOCP = lParam;
	while (true)
	{
		DWORD dwTransfered = 0;// 传输的字节数
		DWORD dwCompleteKey = 0;// 完成键
		PMYOVERLAPPED mol = 0;
		int nRet = GetQueuedCompletionStatus(
			hIOCP, &dwTransfered, &dwCompleteKey, (LPOVERLAPPED*)&mol, INFINITE);
		if (nRet == NULL && GetLastError() == ERROR_ABANDONED_WAIT_0)
		{
			printf("完成端口被关闭\n");
			return 0;
		}
		if (nRet == NULL && dwCompleteKey)
		{
			g_tcp.TcpClientExit(dwCompleteKey);
			printf("客户端退出\n");
			continue;
		}
		// 处理recv
		g_tcp.TcpRecv(dwCompleteKey, mol->buf, 1024);
		printf("%s\n", mol->buf);
		ZeroMemory(mol, sizeof(MYOVERLAPPED));
		mol->wsa.buf = mol->buf;
		mol->wsa.len = 1024;
		DWORD dwFlags = 0;
		WSARecv(
			dwCompleteKey,
			&mol->wsa,//读取的数据放在哪
			1,// 伪大小，把recv操作交给完成端口
			NULL,// 实际读取的大小，有OVERLAPPED不需要它
			&dwFlags,
			(LPOVERLAPPED)mol, NULL);
	}
	return 0;
}
int main()
{
	// 1 准备好完成端口
	SYSTEM_INFO si = {};
	GetSystemInfo(&si);
	HANDLE hIOCP = CreateIoCompletionPort(
		INVALID_HANDLE_VALUE, NULL, NULL, si.dwNumberOfProcessors);
	// 2. 完成端口的服务线程
	for (int i = 0; i < si.dwNumberOfProcessors*2; i++)
	{
		CreateThread(
			NULL, NULL, IOCP_Thread, hIOCP, NULL, NULL);
	}
	// 3. 绑定设备(socket)
	g_tcp.InitServer();
	while (true)
	{
		SOCKET sClient = g_tcp.TcpAccept();
		if (sClient == INVALID_SOCKET) return 0;
		// 把客户端socket和完成端口绑定
		CreateIoCompletionPort((HANDLE)sClient, hIOCP, sClient, NULL);
		PMYOVERLAPPED mol = new MYOVERLAPPED{};
		mol->wsa.buf = mol->buf;
		mol->wsa.len = 1024;
		DWORD dwFlags = 0;
		WSARecv(
			sClient,
			&mol->wsa,//读取的数据放在哪
			1,// 伪大小，把recv操作交给完成端口
			NULL,// 实际读取的大小，有OVERLAPPED不需要它
			&dwFlags,
			(LPOVERLAPPED)mol, NULL);
	}
    return 0;
}

