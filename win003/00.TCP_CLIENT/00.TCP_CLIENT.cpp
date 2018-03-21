// 00.TCP_CLIENT.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
// 1. 包含头文件及库  要写在其他头文件(类似windows.h)之前
#include <WinSock2.h>
#pragma comment(lib,"Ws2_32.lib")
DWORD WINAPI RecvThread(LPVOID lParam) {
	SOCKET sClient = (SOCKET)lParam;
	while (true)
	{
		char buf[1024] = {};
		int nRet = recv(sClient, buf, 1024, NULL);
		if (nRet == SOCKET_ERROR) {
			printf("服务器关闭\n");
			exit(0);
			return 0; 
		}
		printf("%s\n", buf);
	}
	return 0;
}
int main()
{	// 1. 信号检测
	WSADATA wsd = {};
	WSAStartup(MAKEWORD(2, 2), &wsd);
	if (LOBYTE(wsd.wVersion) != 2 ||
		HIBYTE(wsd.wVersion) != 2)
	{
		printf("库版本不支持\n");
		return 0;
	}
	// 2. 买手机
	SOCKET sClient = socket(
		AF_INET,// IP4协议
		SOCK_STREAM,// 流式套接字
		IPPROTO_TCP);// 协议类型(TCP)
	if (sClient == INVALID_SOCKET)
	{
		printf("创建socket失败！\n");
		WSACleanup();
		return 0;
	}
	// 3. 办卡
	SOCKADDR_IN addrSer = {};
	addrSer.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	addrSer.sin_port = htons(0x1234);// host to net short
	addrSer.sin_family = AF_INET;
	int nLen = sizeof(SOCKADDR_IN);
	// 绑定+通讯  直接和服务器通讯，自动绑定
	int nRet = connect(sClient, (SOCKADDR*)&addrSer, nLen);
	if (nRet == SOCKET_ERROR) { /*清理环境 关闭套接字*/return 0; }
	CreateThread(NULL, NULL, RecvThread, (LPVOID)sClient, NULL, NULL);
	while (true)
	{
		char buf[1024] = {};
		scanf_s("%s", buf, 1024);
		nRet = send(sClient, buf, 1024, NULL);
		if (nRet == SOCKET_ERROR)
		{
			closesocket(sClient);
			WSACleanup();
			return 0;
		}
	}
    return 0;
}

