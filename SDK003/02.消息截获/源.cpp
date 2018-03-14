#include <windows.h>
#include "resource.h"

INT_PTR CALLBACK DialogProc(
	_In_ HWND   hwndDlg,
	_In_ UINT   uMsg,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
);



int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DialogProc);
	return 0;
}

WNDPROC g_oldProc = 0;

LRESULT CALLBACK NewProc(
	_In_ HWND   hwndDlg,
	_In_ UINT   uMsg,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
) {
	switch (uMsg)
	{
	case WM_LBUTTONUP:{
		MessageBox(hwndDlg, L"在自己窗口中响应！\n",0,MB_OK);
		return 0;
		}
	default:
		break;
	}
	return g_oldProc(hwndDlg, uMsg, wParam, lParam);
}
INT_PTR CALLBACK DialogProc(
	_In_ HWND   hwndDlg,
	_In_ UINT   uMsg,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
) {
	switch (uMsg)
	{
	case WM_INITDIALOG: {
		break;
	}
	case WM_COMMAND:
	{
		if (LOWORD(wParam) == IDC_BUTTON1 && HIWORD(wParam) == BN_CLICKED)
		{
			MessageBox(hwndDlg, L"父窗口中响应消息", 0, MB_OK);
			// 从此把消息交给自己，没有父窗口的事了
			if (!g_oldProc)
			{
				g_oldProc = (WNDPROC)SetWindowLong((HWND)lParam, GWL_WNDPROC, (LONG)NewProc);
			}
		}
		break;
	}
	case WM_NOTIFY: {
		break;
	}
	case WM_CLOSE: {
		EndDialog(hwndDlg, 0);
		break;
	}
	case WM_RBUTTONUP: {
		break;
	}
	default:
		break;
	}
	return 0;
}

