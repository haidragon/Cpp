
// 01.TCP_SER_MSG.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// CMy01TCP_SER_MSGApp: 
// 有关此类的实现，请参阅 01.TCP_SER_MSG.cpp
//

class CMy01TCP_SER_MSGApp : public CWinApp
{
public:
	CMy01TCP_SER_MSGApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CMy01TCP_SER_MSGApp theApp;