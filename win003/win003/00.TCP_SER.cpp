// win003.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
// 1. 包含头文件及库  要写在其他头文件(类似windows.h)之前
#include <WinSock2.h>
#pragma comment(lib,"Ws2_32.lib")
#include <vector>
using std::vector;
vector<SOCKET> m_vecSocket;
/*
每一个客户端连接进来，都要创建一个线程
三大模型：
消息选择模型
事件选择模型
完成端口模型
*/
DWORD WINAPI RecvThread(LPVOID lParam) {
	SOCKET sClient = (SOCKET)lParam;
	while (true)
	{
		char buf[1024] = {};
		int nRet = recv(sClient, buf, 1024, NULL);
		if (nRet == SOCKET_ERROR) {
			// 把该客户端从数组里删除
			for (int i=0;i<m_vecSocket.size();i++)
			{
				if (m_vecSocket[i] == sClient)
				{
					m_vecSocket.erase(m_vecSocket.begin() + i);
					printf("客户端退出\n");
					break;
				}
			}
			closesocket(sClient);
			return 0; 
		}
		printf("%s\n", buf);
		// 转发给其他的客户端
		for (auto &each:m_vecSocket)
		{
			if(each == sClient) continue;
			send(each, buf, 1024, NULL);
		}
	}
	return 0;
}

int main()
{
	// 1. 信号检测
	WSADATA wsd = {};
	WSAStartup(MAKEWORD(2, 2), &wsd);
	if (LOBYTE(wsd.wVersion) != 2 ||
		HIBYTE(wsd.wVersion) != 2)
	{
		printf("库版本不支持\n");
		return 0;
	}
	// 2. 买手机
	SOCKET sSer = socket(
		AF_INET,// IP4协议
		SOCK_STREAM,// 流式套接字
		IPPROTO_TCP);// 协议类型(TCP)
	if (sSer == INVALID_SOCKET)
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
	int nRet = bind(sSer, (SOCKADDR*)&addrSer, nLen);
	if (nRet == SOCKET_ERROR) {/*关闭套接字，清理环境*/return 0; }
	// 4. 监听
	nRet = listen(sSer, SOMAXCONN);
	if (nRet == SOCKET_ERROR) {/*关闭套接字，清理环境*/return 0; }
	// 5. 等待客户端连接
	SOCKADDR_IN  addrClient = {};
	while (true)
	{
		nLen = sizeof(SOCKADDR_IN);
		// 等待客户端连接
		SOCKET sClient = accept(sSer, (SOCKADDR*)&addrClient, &nLen);
		if (sClient == INVALID_SOCKET) {/*关闭套接字，清理环境*/return 0; }
		// 保存连接进来的客户端
		m_vecSocket.push_back(sClient);
		CreateThread(NULL, NULL, RecvThread, (LPVOID)sClient, NULL, NULL);
	}
	return 0;
}

