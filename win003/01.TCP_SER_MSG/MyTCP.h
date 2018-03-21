#pragma once
#include <WinSock2.h>
#pragma comment(lib,"Ws2_32.lib")
#include <vector>
using std::vector;
class CMyTCP
{
public:
	CMyTCP();
	~CMyTCP();
	SOCKET m_socket;
	vector<SOCKET> m_vecSocket;
	SOCKET TcpAccept();
	int TcpRecv(SOCKET s,char*buf,int nLen);
	bool InitServer(char* pIp="127.0.0.1",short port=0x1234);
	bool TcpClientExit(SOCKET s);
};

