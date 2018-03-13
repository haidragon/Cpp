#include <windows.h>
#include "resource.h"
INT_PTR CALLBACK DialogProc(
	_In_ HWND   hwndDlg,
	_In_ UINT   uMsg,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
);



int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {
	// 模态对话框  和非模态对话框
	// 内部自带循环 阻塞后面代码的就是模态
	// 否则就是非模态对话框
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DialogProc);
	//MessageBox(0, 0, 0, 0);
	//	HWND hWnd = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DialogProc);
//	while (...)
//	{
//...消息循环
//	}
	return 0;
}

INT_PTR CALLBACK DialogProc(
	_In_ HWND   hwndDlg,
	_In_ UINT   uMsg,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
) {
	// 和窗口回调函数不一样 
	// 1. 返回值不一样
	// 2. 结束方式不一样 一个是postquitmessage   一个是EndDialog
	// 3. 初始化消息不同WM_CREATE WM_INITDIALOG
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		break;
	}
	case WM_COMMAND: {
		WORD wId = LOWORD(wParam);
		WORD wCode = HIWORD(wParam);
		HANDLE hChild = (HANDLE)lParam;
		if (wId == IDC_BUTTON1 && wCode == BN_CLICKED)
		{
			// 移动父窗口
			MoveWindow(hwndDlg, 500, 500, 1000, 1000, true);
			// 移动其他窗口  当前程序
			// 得到子控件的句柄
			HWND hwnd = GetDlgItem(hwndDlg, IDC_BUTTON2);
			MoveWindow(hwnd, 20,20, 500, 100, true);
			// 移动其他窗口 其他程序
			MoveWindow((HWND)(0x0B08C4), 20, 20, 500, 100, true);
		}
		break;
	}
	case WM_CLOSE:
	{
		EndDialog(hwndDlg, 0);
		break;
	}
	default:
		break;
	}
	return 0;
}