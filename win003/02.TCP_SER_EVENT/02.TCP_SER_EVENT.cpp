// 02.TCP_SER_EVENT.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MyTCP.h"

int main()
{
	vector<HANDLE> m_vecEvent;
	vector<SOCKET> m_vecSocket;
	CMyTCP tcp;
	tcp.InitServer();
	HANDLE hEvent = WSACreateEvent();
	m_vecEvent.push_back(hEvent);
	// 当m_socket需要响应FD_ACCEPT | FD_CLOSE事件时
	// 系统会激活hEvent，把它变成有信号状态
	WSAEventSelect(tcp.m_socket, hEvent, FD_ACCEPT | FD_CLOSE);
	m_vecSocket.push_back(tcp.m_socket);
	while (true)
	{
		int nCount = m_vecEvent.size();
		// nCount不能超过64
		int nRet = WSAWaitForMultipleEvents(
			nCount,// 等待的事件个数 HEVENT
			&m_vecEvent[0], // 等待的多个事件的数组地址
			FALSE, // 是否等待所有事件都被激活
			INFINITE,// 等待超时时间
			FALSE);// 是否可警醒
		if (nRet == WSA_WAIT_FAILED) continue;
		int nIndex = nRet - WSA_WAIT_EVENT_0;
		// 获取被激活的事件对应的socket的网络事件
		WSANETWORKEVENTS we = {};
		WSAEnumNetworkEvents(m_vecSocket[nIndex], m_vecEvent[nIndex], &we);
		if (we.lNetworkEvents & FD_ACCEPT)
		{
			SOCKET s = tcp.TcpAccept();
			HANDLE hEvent2 = WSACreateEvent();
			m_vecEvent.push_back(hEvent2);
			// 当m_socket需要响应FD_ACCEPT | FD_CLOSE事件时
			// 系统会激活hEvent，把它变成有信号状态
			WSAEventSelect(s, hEvent2, FD_READ | FD_CLOSE);
			m_vecSocket.push_back(s);
		}
		if (we.lNetworkEvents & FD_READ)
		{
			char buf[1024] = {};
			tcp.TcpRecv(m_vecSocket[nIndex], buf, 1024);
			printf("%s\n", buf);
		}
		if (we.lNetworkEvents & FD_CLOSE)
		{
			if (we.iErrorCode[FD_CLOSE_BIT] != 0)
				printf("客户端流氓式关闭\n");
			else
			{
				printf("客户端退出\n");
			}
			tcp.TcpClientExit(m_vecSocket[nIndex]);
		}
	}
    return 0;
}

