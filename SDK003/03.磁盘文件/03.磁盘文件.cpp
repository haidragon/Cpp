// 03.磁盘文件.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
#include <locale.h>

void FunDisk() {
	setlocale(LC_ALL, "CHS");
	// 先获取PC上的所有磁盘
	TCHAR szPaths[MAX_PATH] = {};
	GetLogicalDriveStrings(MAX_PATH, szPaths);
	TCHAR *pTemp = szPaths;// C:\ 
	const TCHAR *pSzType[] = {
	L"未知类型",L"无效的根路径",L"移动磁盘",L"硬盘",L"网络磁盘",L"CD",L"RAM"
	};
	while (*pTemp)
	{
		printf("%S: ", pTemp);
		int nRet = GetDriveType(pTemp);
		printf("%S  ", pSzType[nRet]);
		// 磁盘容量
		DWORD 剩余簇数量;
		DWORD 总的簇数量;
		DWORD 每簇扇区数;
		DWORD 扇区字节数;
		GetDiskFreeSpace(pTemp, &每簇扇区数, &扇区字节数, &剩余簇数量, &总的簇数量);
		printf("剩余容量：%.2fG  总容量：%.2fG\n",
			剩余簇数量/1024.0*每簇扇区数*扇区字节数/1024/1024  ,
			总的簇数量/1024.0*每簇扇区数*扇区字节数/1024/1024 );
		pTemp += wcslen(pTemp) + 1;
	}
}

// 文件操作
void FunFile() {
	// 先打开/创建新文件
	HANDLE hFile = CreateFile(
		L"temp.dat",// 文件路径
		GENERIC_READ | GENERIC_WRITE,//想要获取的操作权限
		FILE_SHARE_READ,//共享权限
		NULL,// 默认的安全描述符
		OPEN_ALWAYS,//打开已经存在的或创建新的
		FILE_ATTRIBUTE_NORMAL,// 文件属性
		NULL//模板文件
	);
	// 写
	//DWORD dwWriten = 0;
	//WriteFile(hFile, "abcd",// 从哪个地址开始写
	//	4,// 写几个
	//	&dwWriten,// 实际写入的字节数
	//	NULL);// 异步IO
	//// 读
	//SetFilePointer(hFile,
	//	0, 0, // 距离最后一个参数的移动距离
	//	FILE_BEGIN);
	//char buf[10] = {};
	//DWORD dwRead = 0;
	//ReadFile(hFile, buf, 10, &dwRead, NULL);
	//printf("%s", buf);
	// 读取文件的全部内容
	DWORD dwSize = GetFileSize(hFile, NULL);
	PBYTE pBuf = new BYTE[dwSize]{};
	ReadFile(hFile, pBuf, dwSize, &dwSize, NULL);
	// 拷贝 删除
	//CopyFile;
	//DeleteFile;
	CloseHandle(hFile);
}

void EnumDir(const TCHAR *pDir) {
	TCHAR szSearchPath[MAX_PATH] = {};
	_stprintf_s(szSearchPath, MAX_PATH, L"%s\\*", pDir);
	WIN32_FIND_DATA wsd = {};
	HANDLE hFile = FindFirstFile(szSearchPath, &wsd);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		return;
	}
	do 
	{
		printf("%S\n", wsd.cFileName);
		if (!wcscmp(wsd.cFileName,L".")||
			!wcscmp(wsd.cFileName, L".."))
		{
			continue;
		}
		if (wsd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			// 是个目录 
			TCHAR 递归[MAX_PATH] = {};
			_stprintf_s(递归, MAX_PATH, L"%s\\%s", pDir,wsd.cFileName);
			EnumDir(递归);
		}
	} while (FindNextFile(hFile,&wsd));
}

int main()
{
	// 获取磁盘信息
	FunDisk();
	FunFile();
	// 遍历磁盘文件
	EnumDir(L"e:");
	return 0;
}

