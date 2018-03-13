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


BOOL CALLBACK EnumChildProc(
	_In_ HWND   hwnd,
	_In_ LPARAM lParam
) {
	static int nCount = 0;
	if (nCount == 6)
	{
		nCount = 0;
		*(HWND*)lParam = hwnd;
		return false;
	}
	nCount++;
	return true;
}


INT_PTR CALLBACK DialogProc(
	_In_ HWND   hwndDlg,
	_In_ UINT   uMsg,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
) {
	switch (uMsg)
	{
	case WM_COMMAND: {
		WORD wId = LOWORD(wParam);
		WORD wCode = HIWORD(wParam);
		HANDLE hChild = (HANDLE)lParam;
		if (wId == IDC_BUTTON1 && wCode == BN_CLICKED)
		{
			// 1. 既有类名也有窗口名
			HWND hCalc = FindWindow(L"CalcFrame", L"计算器");
			//MoveWindow(hCalc, 0, 0, 500, 500, true);
			//MessageBox(0, 0, 0, 0);
			// 2. 有类名 没有窗口名 
			HWND hChild = GetWindow(hCalc, GW_CHILD);
			//MoveWindow(hChild, 0, 0, 500, 500, true);
			// 3. 需要多次调用GetWindow的时候
			// 把hChild的子窗口句柄一次传递给EnumChildProc
			HWND hLoop = 0;
			EnumChildWindows(hChild, EnumChildProc, (LPARAM)&hLoop);
			//MoveWindow(hLoop, 50, 50, 500, 500, true);
			// 4. 获取子控件句柄
			HWND hFinal = GetDlgItem(hLoop, 0x83);
			//MoveWindow(hFinal, 100, 100, 200, 50, true);
			SendMessage(hLoop, WM_COMMAND, MAKEWPARAM(0x83, BN_CLICKED), (LPARAM)hFinal);

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