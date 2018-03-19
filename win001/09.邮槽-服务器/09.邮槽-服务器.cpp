// 09.邮槽-服务器.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>

int main()
{
	HANDLE hMailSlot = CreateMailslot(
		L"\\\\.\\mailslot\\sample",// 邮槽名
		0,// 无最大消息限制
		MAILSLOT_WAIT_FOREVER,// 永不超时
		NULL
	);
	while (true)
	{
		DWORD dwCount = 0, dwSize = 0;
		GetMailslotInfo(
			hMailSlot,// 邮槽名
			NULL,// 无最大消息限制
			&dwSize,// 下一条消息大小
			&dwCount,// 消息个数
			NULL);// 永不超时
		if (dwSize == MAILSLOT_NO_MESSAGE)
		{
			Sleep(200);// 暂时没有消息
			continue;
		}
		while (dwCount)
		{
			PBYTE pBuf = new BYTE[dwSize+10]{};
			ReadFile(hMailSlot, pBuf, dwSize, &dwSize, NULL);
			printf("%s\n", pBuf);
			GetMailslotInfo(hMailSlot, 0, &dwSize, &dwCount, NULL);
			delete[] pBuf;
		}
	}
    return 0;
}

