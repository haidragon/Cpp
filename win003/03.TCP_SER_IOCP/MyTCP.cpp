#include "stdafx.h"
#include "MyTCP.h"


CMyTCP::CMyTCP()
{
}


CMyTCP::~CMyTCP()
{
}

SOCKET CMyTCP::TcpAccept()
{
	SOCKADDR addr = {};
	int nLen = sizeof(SOCKADDR);
	SOCKET s = accept(m_socket, &addr, &nLen);
	if (s == INVALID_SOCKET)
	{
		return INVALID_SOCKET;
	}
	m_vecSocket.push_back(s);
	return s;
}



int CMyTCP::TcpRecv(SOCKET s, char*buf, int nLen)
{
	for (auto &each:m_vecSocket)
	{
		if(each == s) continue;
		send(each, buf, nLen, NULL);
	}
	return true;
}

bool CMyTCP::InitServer(char* pIp/*="127.0.0.1"*/, short port/*=0x1234*/)
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
	m_socket = socket(
		AF_INET,// IP4协议
		SOCK_STREAM,// 流式套接字
		IPPROTO_TCP);// 协议类型(TCP)
	if (m_socket == INVALID_SOCKET)
	{
		printf("创建socket失败！\n");
		WSACleanup();
		return 0;
	}
	// 3. 办卡
	SOCKADDR_IN addrSer = {};
	addrSer.sin_addr.S_un.S_addr = inet_addr(pIp);
	addrSer.sin_port = htons(port);// host to net short
	addrSer.sin_family = AF_INET;
	int nLen = sizeof(SOCKADDR_IN);
	int nRet = bind(m_socket, (SOCKADDR*)&addrSer, nLen);
	if (nRet == SOCKET_ERROR) {/*关闭套接字，清理环境*/return 0; }
	// 4. 监听
	nRet = listen(m_socket, SOMAXCONN);
	if (nRet == SOCKET_ERROR) {/*关闭套接字，清理环境*/return 0; }
	return true;
}

bool CMyTCP::TcpClientExit(SOCKET s)
{
	for (int i=0;i<m_vecSocket.size();i++)
	{
		if (m_vecSocket[i] == s)
		{
			m_vecSocket.erase(m_vecSocket.begin() + i);
			closesocket(s);
			return true;
		}
	}
	return false;
}
