// 0. 改变项目属性，设置为使用MFC库
// 1. 包含MFC的头文件
#include <afxwin.h>
#include "MyDlg.h"// 对话框资源创建的类
// 2. 派生一个继承自CWinApp的类
class CMyApp :public CWinApp {
	// 3. 重写该类的虚函数InitInstance
	BOOL InitInstance()override {
		// 4. 创建窗口，把窗口指针赋值给基类的成员变量m_pMainWnd
		// 创建普通窗口
	/*	CFrameWnd *p = new CFrameWnd;
		p->Create(NULL, L"我的第一个MFC窗口！");
		p->ShowWindow(SW_SHOW);
		m_pMainWnd = p;*/

		// 通过资源创建对话框
		// a. 添加对话框资源，对话框上右键添加类
		// b. 在类的.h文件中添加头文件包含
		//#include "resource.h"
		//#include <afxdialogex.h>
		// C. 当前cpp包含#include "MyDlg.h"
		// d. 创建自定义资源对话框
		CMyDlg *p = new CMyDlg;
		m_pMainWnd = p;
		// e. 非模态
		//p->Create(IDD_DIALOG1, NULL);
		//p->ShowWindow(SW_SHOW);
		// f. 模态
		p->DoModal();
		return TRUE;
	}
};
// 5. 创建该类的全局变量

CMyApp theApp;