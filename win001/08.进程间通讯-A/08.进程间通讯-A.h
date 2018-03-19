
// 08.进程间通讯-A.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// CMy08进程间通讯AApp: 
// 有关此类的实现，请参阅 08.进程间通讯-A.cpp
//

class CMy08进程间通讯AApp : public CWinApp
{
public:
	CMy08进程间通讯AApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CMy08进程间通讯AApp theApp;